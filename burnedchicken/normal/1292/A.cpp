#include <bits/stdc++.h>
 
#define ll long long
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
bool grid[2][100005];
multiset<int> st;
int n,q,cnt;

bool legal(int x, int n){return 0<=x&&x<=n-1;}

void query(){
	int x,y;
	cin >> x >> y;
	x--,y--;
	grid[x][y]=grid[x][y]?false:true;
	if(x){
		if(grid[x][y]){
			st.insert(y-1),st.insert(y),st.insert(y+1);
			if(legal(y-1,n)) if(grid[0][y-1]) cnt++;
			if(legal(y,n)) if(grid[0][y]) cnt++;
			if(legal(y+1,n)) if(grid[0][y+1]) cnt++;
		}
		else{
			st.erase(st.find(y-1)),st.erase(st.find(y)),st.erase(st.find(y+1));
			if(legal(y-1,n)) if(grid[0][y-1]) cnt--;
			if(legal(y,n)) if(grid[0][y]) cnt--;
			if(legal(y+1,n)) if(grid[0][y+1]) cnt--;
		}
	}
	else{
		if(grid[x][y]) cnt+=st.count(y);
		else cnt-=st.count(y);
	}
	if(cnt) cout << "No\n";
	else cout << "Yes\n";
	return;
}
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n >> q;
	rep(2) rep1(j,100005) grid[i][j]=false;
	cnt=0;
	while(q--) query();
	return 0;
}