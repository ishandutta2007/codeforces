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
ll t,n,m,i,j;
pi pos[5];
pi ans1,ans2;
ll val;
ll getdis(pi a,pi b){
	return abs(a.fr-b.fr)+abs(a.se-b.se);
}
ll getway(pi a,pi b,pi c){
	return min(getdis(a,b)+getdis(b,c)+getdis(c,a),getdis(a,c)+getdis(c,b)+getdis(b,a));
}
int main(){
	cin>>t;
	while(t--){
		cin>>n>>m>>i>>j;val=0;
		pos[1]=mp(1,1);pos[2]=mp(1,m);pos[3]=mp(n,1);pos[4]=mp(n,m);
		rep(i,1,3){
			rep(j,i+1,4){
				if(getway(mp(i,j),pos[i],pos[j])>val){
					val=getway(mp(i,j),pos[i],pos[j]);
					ans1=pos[i];ans2=pos[j];
				}
			}
		}
		printf("%d %d %d %d\n",ans1.fr,ans1.se,ans2.fr,ans2.se);
	}

	return 0;
}