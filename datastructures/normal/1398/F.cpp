#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct node{
	int pos,mx;
	bool operator <(const node &x)const{
		return mx<x.mx;
	}
}a[1000005];
int n,len[1000005],m,c[1000005],_c[1000005],sta[2000005],tot;
int l,d[1000005];
int f[1000005];
char s[1000005];
int main(){
	cin>>n;
	scanf("%s",s+1);
	s[0]='$',s[n+1]='$';
	int fir=0;
	while(fir<=n&&s[fir]!='0'&&s[fir]!='1')fir++;
	if (fir>n){
		for (int i=1;i<=n;i++)printf("%d ",n/i);
		puts("");
		return 0;
	}
	c[0]=fir-1;
	for (int i=fir;i<=n;){
		int j=i;
		while(j<=n&&s[j]!='1'-(s[i]-'0'))j++;
		int k=j-1;
		while(s[k]=='?')k--;
		++m;
		len[m]=k-i+1;
		c[m]=j-k-1;
		i=j;
	}
	for (int i=0;i<=m;i++)_c[i]=c[i];
	for (int i=1;i<=m;i++)a[i].pos=i,a[i].mx=len[i]+c[i-1]+_c[i];
	sort(a+1,a+1+m);
	int j=1;
	for (int i=1;i<=n;i++){
		while(j<=m&&a[j].mx<i)j++;
		int ans=0;
		l=0;
		for (int k=j;k<=m;k++)d[++l]=a[k].pos;
		sort(d+1,d+1+l);
		for (int k=1;k<=l;k++){
			int pos=d[k];
			sta[++tot]=pos-1,sta[++tot]=pos;
			int num=len[pos]+c[pos-1];
			c[pos-1]=0;
			int delta,t;
			delta=i-num%i;
			if (delta==i)delta=0;
			if (c[pos]>=delta)num+=delta,c[pos]-=delta;
			t=c[pos]/i;
			num+=t*i,c[pos]-=t*i;
			ans+=num/i;
		}
		f[i]=ans;
		while(tot)c[sta[tot]]=_c[sta[tot]],tot--;
	}
	for (int i=1;i<=n;i++)printf("%d ",f[i]);
	puts("");
	return 0;
}