#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define ll long long
using namespace std;
const int N=1e6+6,P=1e9+7;
int a[N],b[N],c[N]; char s[N];
signed main(){
	int n; scanf("%d%s",&n,s);
	a[0]=1,b[0]=0,c[0]=0; int ans=0;
	rep(i,1,n){
		a[i]=s[i-1]=='?'?3LL*a[i-1]%P:a[i-1];
		if (s[i-1]=='?') b[i]=(3LL*b[i-1]+a[i-1])%P;
		else if (s[i-1]=='a') b[i]=(b[i-1]+a[i-1])%P;
		else b[i]=b[i-1];
		if (s[i-1]=='?') c[i]=(3LL*c[i-1]+b[i-1])%P;
		else if (s[i-1]=='b') c[i]=(c[i-1]+b[i-1])%P;
		else c[i]=c[i-1];
		if (s[i-1]=='?') ans=(3LL*ans+c[i-1])%P;
		else if (s[i-1]=='c') ans=(ans+c[i-1])%P;
	}
	cout<<ans<<endl;
	return 0;
}