#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[200004];
int d[200004];
int sol(){
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;i++)d[i]=d[i-1]+(s[i]-'0');
	int G=__gcd(d[n],n),dx=d[n]/G,dm=n/G;
	if(m%dm!=0)return puts("-1"),0;
	int t=m/dm*dx;
	for(int i=m;i<=n;i++)if(d[i]-d[i-m]==t)
		return printf("1\n%d %d\n",i-m+1,i),0;
	for(int l=m,r=n+1;l;l--,r--)
		if(d[l]+d[n]-d[r-1]==t)
			return printf("2\n%d %d\n%d %d\n",1,l,r,n),0;
	return puts("-1"),0;
}
int main(){
	int t;scanf("%d",&t);
	while(t--)sol();
}