#include <iostream>
#include <cstdio>
#define mod 998244353
#define base 30
#define int long long
using namespace std;
int n,a,b,pw[5005],hs[5005],f[5005];
char s[5005];
inline int hashval(register int l,register int r){
	return (hs[r]-hs[l-1]*pw[r-l+1]%mod+mod)%mod;
}
inline int check(register int x,register int y){
	register int len=y-x+1,val=hashval(x,y);
	for (register int i=1;i+len-1<x;i++)
		if (hashval(i,i+len-1)==val)return 1;
	return 0;
}
signed main(){
	cin>>n>>a>>b;
	scanf("%s",s+1);
	pw[0]=1;
	for (register int i=1;i<=n;i++)pw[i]=pw[i-1]*base%mod;
	for (register int i=1;i<=n;i++)hs[i]=(hs[i-1]*base+s[i]-'a'+1)%mod;
	for (register int i=1;i<=n;i++){
		f[i]=f[i-1]+a;
		register int l=1,r=i,ans=0;
		while(l<=r){
			register int mid=(l+r)/2;
			if (check(mid,i))ans=mid,r=mid-1;
			else l=mid+1;
		}
		if (ans)f[i]=min(f[i],f[ans-1]+b);
	}
	cout<<f[n]<<endl;
	return 0;
}