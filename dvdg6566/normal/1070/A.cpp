#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
const ll MAXN = 5010;
const int MAXD = 510;

typedef pair<int,pi> ii;
pair<int, pi> vis[MAXD][MAXN];
int D,S;
queue<pi> Q;

int main(){
	cin>>D>>S;
	for (int i=0;i<D;++i)for (int j=0;j<=S;++j)vis[i][j] = mp(-1,mp(-1,-1));
	Q.push(mp(0,0));
	while (SZ(Q)){
		int m = Q.front().f;
		int s = Q.front().s;
		// cout<<m<<' '<<s<<'\n';
		Q.pop();
		for (int k=0;k<=9;++k){
			if (m==0&&s==0&&k==0)continue;
			int new_m = (m*10+k)%D;
			int new_s = s+k;
			if (new_s > S)continue;
			if (vis[new_m][new_s].f!=-1)continue;
			vis[new_m][new_s] = mp(k, mp(m,s));
			Q.push(mp(new_m,new_s));
		}
	}
	ii cur = vis[0][S];
	if (cur.f == -1){cout<<-1<<'\n';return 0;}
	vi ans;
	while (1){
		if (cur.s.f==0&cur.s.s==0)break;
		ans.pb(cur.f);
		cur = vis[cur.s.f][cur.s.s];
	}
	ans.pb(cur.f);
	reverse(ALL(ans));
	for (auto i:ans)cout<<i;
}