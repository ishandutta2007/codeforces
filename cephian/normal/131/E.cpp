#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int N = 1e5+5;
int ans[N],t[9];

map<int,vector<pii> > M[4];

int main() {	
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 0; i < m; ++i) {
		int x,y;
		scanf("%d%d",&x,&y);
		M[0][x].emplace_back(y,i);
		M[1][y].emplace_back(x,i);
		M[2][x+y].emplace_back(x,i);
		M[3][x-y].emplace_back(x,i);
	}
	for(int i = 0; i < 4; ++i) {
		for(auto &q : M[i]) {
			vector<pii> &v = q.se;
			sort(v.begin(),v.end());
			for(int i = 0; i < v.size(); ++i) {
				if(i != 0) ++ans[v[i].se];
				if(i != v.size()-1) ++ans[v[i].se];
			}
		}
	}
	for(int i = 0; i < m; ++i)
		++t[ans[i]];
	printf("%d %d %d %d %d %d %d %d %d\n",t[0],t[1],t[2],t[3],t[4],t[5],t[6],t[7],t[8]);
}