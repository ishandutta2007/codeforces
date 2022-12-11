#include<bits/stdc++.h>
using namespace std;
const int N=2e6+50;
int T,n,nxt[N],len,mxlen[N],p1,p2;char s[N],t[N],ss[N];
void solve(){
	scanf("%s",s+1);n=strlen(s+1);p1=p2=len=0;
	for(int i=1;i<=n;i++)ss[i*2-1]='#',ss[i*2]=s[i];ss[n*2+1]='#';ss[0]='^';ss[n*2+2]='%';
	for(int i=1,r=0,m=0;i<=n*2+1;i++){
		if(i<=r)mxlen[i]=min(r-i+1,mxlen[2*m-i]);else mxlen[i]=0;
		while(ss[i-mxlen[i]]==ss[i+mxlen[i]])mxlen[i]++;
		if(i+mxlen[i]-1>r)r=i+mxlen[i]-1,m=i;
	}
	for(int i=1;i<=n/2;i++)if(s[i]==s[n-i+1])len=i;else break;
	for(int i=1;i<=n;i++){
		int l=mxlen[i*2]/2;
		if(i<=n/2&&i-l<=len){
			if(i+l-1+i-l>p1+p2)p1=i+l-1,p2=i-l;
		}
		if(i>n/2&&n-(i+l)+1<=len){
			if(n-(i+l)+1+n-(i-l+1)+1>p1+p2)p2=n-i+l,p1=n-i-l+1;
		}
	}
	for(int i=1;i<n;i++){
		int l=mxlen[i*2+1]/2;
		if(i<=n/2&&i-l<=len){
			if(i+l+i-l>p1+p2)p1=i+l,p2=i-l;
		}
		if(i>n/2&&n-(i+l)<=len){
			if(n-(i+l)+n-i+l>p1+p2)p2=n-i+l,p1=n-i-l;
		}
	}
	for(int i=1;i<=p1;i++)putchar(s[i]);
	for(int i=n-p2+1;i<=n;i++)putchar(s[i]);puts("");
}
int main(){
	scanf("%d",&T);
	while(T--)solve();
}