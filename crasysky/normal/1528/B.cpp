#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define pb push_back
#define db long double
using namespace std;
const int N=1e6+6,P=998244353;
int f[N],s[N],d[N];
int main(){
	int n; cin>>n;
	rep(i,1,n) rep(j,2,n/i) ++d[i*j];
	f[0]=f[1]=1,s[1]=2;
	rep(i,2,n){
		f[i]=(s[i-1]+d[i])%P,s[i]=(s[i-1]+f[i])%P;
	}
	cout<<f[n]<<endl;
	return 0;
}