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
const ll MAXN=1e5+10,MAXL=(1<<18)+10,LIM=(1<<18);
ll T,n,k,a[MAXN],ans=-1e18,tmp[5];
pi f[MAXL];
void update(pi& p1,pi p2){
	tmp[0]=p1.fr;tmp[1]=p2.fr;tmp[2]=p1.se;tmp[3]=p2.se;
	sort(tmp,tmp+4);
	p1.fr=tmp[3];
	if(tmp[2]!=tmp[3])p1.se=tmp[2];
	else if(tmp[1]!=tmp[3])p1.se=tmp[1];
	else p1.se=tmp[0];
}
int main(){
	cin>>T;
	while(T--){
		cin>>n>>k;
		rep(i,1,n){
			cin>>a[i];
		}
		ans=-1e18;
		rep(i,0,Min(LIM,n*3)){
			f[i]=mp(-1e9,-1e9);
		}
		/*
		rep(i,0,3){
			printf("%lld %lld")
		}
		*/
		rep(i,1,n){
			update(f[a[i]],mp(i,-1e9));
		}
		rep(i,0,Min(LIM,n*3)){
			rep(j,0,17){
				if(i&(1<<j))continue;
				if((i|(1<<j))> 3*n)continue;
				int k=(i|(1<<j));
				update(f[k],f[i]);
			}
		}
		rep(i,0,Min(LIM,n*3)){
			if(f[i].fr==-1e9 || f[i].se==-1e9)continue;
			ans=Max(ans,(ll)f[i].fr*f[i].se-k*i);
		}
		cout<<ans<<endl;
	}
	

	return 0;
}
/*
4
3 3
1 1 3
*/