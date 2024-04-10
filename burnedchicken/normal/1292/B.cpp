#include <bits/stdc++.h>
 
#define ll long long
#define ull unsigned long long
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<(int(a)); i++)
#define all(a) a.begin(),a.end()
#define forall(a,type) for(type::iterator it=a.begin(); it!=a.end(); it++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define pow2(x) (1ll<<(x))
 
using namespace std;
 
const int Mod=1e9+7;
ull xx,yy,ax,ay,bx,by,xs,ys,t,tmp;
vector<ull> vec[2];
ull num=40000000000000000;
int ans=0;

ull dist(ull a1, ull a2, ull a3, ull a4){return max(a1,a3)-min(a1,a3)+max(a2,a4)-min(a2,a4);}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> xx >> yy >> ax >> ay >> bx >> by >> xs >> ys >> t;
	vec[0].pb(xx);
	vec[1].pb(yy);
	while(1){
		vec[0].pb(ax*vec[0].back()+bx);
		vec[1].pb(ay*vec[1].back()+by);
		if(vec[0].back()+vec[1].back()>num){
			vec[0].pop_back();
			vec[1].pop_back();
			break;
		}
	}
	rep(vec[0].size()){
		rep2(j,i,vec[0].size()){
			tmp=min(dist(xs,ys,vec[0][i],vec[1][i]),dist(xs,ys,vec[0][j],vec[1][j]))+dist(vec[0][i],vec[1][i],vec[0][j],vec[1][j]);
			if(tmp<=t) ans=max(ans,j-i+1);
		}
	}
	cout << ans << "\n";
	return 0;
}