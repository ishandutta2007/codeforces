#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<(a); i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pow2(x) (1ll<<(x))
 
using namespace std;
 
const int Mod=1e9+7;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	ll n,m;
	cin >> n >> m;
	ll e[m][3];
	loop(m) loopi(j,3) cin >> e[i][j];
	ll num[n+1];
	loop(n+1) num[i]=0;
	loop(m){
		num[e[i][0]]+=e[i][2];
		num[e[i][1]]-=e[i][2];
	}
	vector<ll> vec[3];
	ll x,y;
	x=y=1;
	while(x<n||y<n){
		if(num[x]<=0) x++;
		if(num[y]>=0) y++;
		if(num[x]>0&&num[y]<0){
			vec[0].push_back(x);
			vec[1].push_back(y);
			vec[2].push_back(min(num[x],-num[y]));
			num[x]-=vec[2].back();
			num[y]+=vec[2].back();
		}
	}
	cout << vec[0].size() << "\n";
	loop(vec[0].size()){
		loopi(j,3) cout << vec[j][i] << " ";
		cout << "\n";
	}
	return 0;
}