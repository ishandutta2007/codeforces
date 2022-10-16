#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
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
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=110,INF=1e9,LIM=100;
int T,n,a,b,ans,cnt;
int f[MAXN];
char s[MAXN];
int main(){
	cin>>T;
	f[1]=1;
	f[2]=2;
	rep(i,3,LIM){
		f[i]=1+f[i-2];
	}
	while(T--){
		cin>>n>>a>>b;
		cin>>(s+1);
		ans=a*n;
		if(b>=0){
			ans+=b*n; 
		}else{
			cnt=1;
			rep(i,2,n){
				if(s[i]!=s[i-1])cnt++;
			}
			ans+=b*f[cnt];
		}
		cout<<ans<<endl;
	}

	return 0;
}