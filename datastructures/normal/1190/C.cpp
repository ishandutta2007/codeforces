#include <iostream>
#include <cstdio>
using namespace std;
int n,k,pre[100005],suf[100005],fg1=0,fg2=1;
int c0[100005],c1[100005],d0[100005],d1[100005];
char s[100005];
int main(){
	cin>>n>>k;
	scanf("%s",s+1);
	for (register int i=1;i<=n;i++)pre[i]=pre[i-1]+s[i]-'0';
	for (register int i=n;i>=1;i--)suf[i]=suf[i+1]+s[i]-'0';
	for (register int i=1;i+k-1<=n;i++){
		if (pre[i-1]+suf[i+k]==0)fg1=1;
		if (pre[i-1]+suf[i+k]==n-k)fg1=1;
	}
	int first0=0,first1=0,last0=0,last1=0;
	for (register int i=1;i<=n;i++){
		c0[i]=c0[i-1],c1[i]=c1[i-1];
		if (s[i]=='0'){
			last0=i;
			if (first0==0)first0=i;
			c0[i]=max(c0[i],last0-first0);
		}
		if (s[i]=='1'){
			last1=i;
			if (first1==0)first1=i;
			c1[i]=max(c1[i],last1-first1);
		}
	}
	first0=first1=last0=last1=0;
	for (register int i=n;i>=1;i--){
		d0[i]=d0[i+1],d1[i]=d1[i+1];
		if (s[i]=='0'){
			first0=i;
			if (last0==0)last0=i;
			d0[i]=max(d0[i],last0-first0);
		}
		if (s[i]=='1'){
			first1=i;
			if (last1==0)last1=i;
			d1[i]=max(d1[i],last1-first1);
		}
	}
	for (register int i=1;i+k-1<=n;i++){
		if ((i>1)&&(pre[i-1]<i-1)&&(i+k-1<n)&&(suf[i+k]<(n-(i+k-1))))fg2=0;
		if ((i>1)&&(pre[i-1]>0)&&(i+k-1<n)&&(suf[i+k]>0))fg2=0;
		if (max(max(c0[i-1],c1[i-1]),max(d0[i+k],d1[i+k]))>=k)fg2=0;
	}
	if (fg1==1)puts("tokitsukaze");
	else if (fg2==1)puts("quailty");
	else puts("once again");
	return 0;
}