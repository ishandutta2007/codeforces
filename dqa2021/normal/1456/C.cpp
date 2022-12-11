#include<cstdio>
#include<algorithm>
#include<cctype>
#include<iostream>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
typedef long long ll;

int n,k;
ll B;
ll c[500010];
ll S[500010];
ll f[500010];
int main()
{
	n=read(),k=read()+1;
	for (int i=1;i<=n;i++){
		c[i]=read(); B-=c[i];
	}
	sort(c+1,c+n+1);
	for (int i=n;i;i--) S[i]=S[i+1]+c[i];
	for (int i=n;i;i--){
		f[i]=f[i+1]+i*c[i];
	}
	ll ans=-1e18; ll T=0;
	for (int i=0;i<=n;i++){
		int t=(i+k-1)/k;
		if (i) T+=t*c[i];
		ans=max(ans,f[i+1]+S[i+1]*(-i+t)+T);
	}
	cout<<ans+B<<endl;
	return 0;
}