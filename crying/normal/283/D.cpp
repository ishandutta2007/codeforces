#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=5e3+10;
ll n,a[MAXN],f[MAXN];
ll p[MAXN],ans;
int main(){
	cin>>n;
	ans=n;
	rep(i,1,n){
		cin>>a[i];
		while(a[i]%2==0){
			a[i]/=2;
			p[i]++;
		}
	}
	rep(i,2,n){
		f[i]=i-1;
		per(j,i-1,1){
			ll len=i-j-1;
			if(a[j]%a[i]==0 && (p[i]<=len || p[i]-p[j]==len+1))f[i]=Min(f[i],f[j]+len);
		}
	}
	rep(i,1,n){
		ans=Min(ans,f[i]+n-i);
	}
	printf("%lld",ans);
	return 0;
}