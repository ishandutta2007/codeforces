#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
ll MOD = 1e9+7;
ll INF = 1e9;

vpi V;
vi dif,P;
ll N,a,b;

int main(){
	// freopen("in.txt","r",stdin);
	cin>>N;
	for (int i=1;i<=N;++i){
		cin>>a;
		V.pb(mp(a,i));
		P.pb(a);
	}
	sort(ALL(V));
	for (int i=1;i<SZ(V);++i){
		dif.pb(V[i].f - V[i-1].f);
	}
	sort(ALL(dif));
	dif.resize(unique(ALL(dif)) - dif.begin());

	if (SZ(dif) == 1){
		cout<<V.back().s;
		return 0;
	}

	if (SZ(dif) == 3){
		if (dif[0] + dif[1] != dif[2]){cout<<-1;return 0;}
		vi occ;
		occ.pb(-1);occ.pb(-1);occ.pb(-1);
		for (int i=0;i<N-1;++i){
			int d = V[i+1].f-V[i].f;

			if (d == dif[0]){
				if(occ[0] != -1){cout<<-1;return 0;}
				occ[0]=i;
			}
			if (d == dif[1]){
				if(occ[1] != -1){cout<<-1;return 0;}
				occ[1]=i;
			}
		}

		if (abs(occ[1] - occ[0]) == 1){cout<<V[min(occ[0],occ[1])+1].s;return 0;}
		else {cout<<-1;return 0;}
	}
	if (SZ(dif) == 2){
		vi occ;
		occ.pb(0);occ.pb(0);
		for (int i=0;i<N-1;++i){
			int d = V[i+1].f-V[i].f;
			if (d == dif[0]){
				occ[0]++;
			}
			if (d == dif[1]){
				occ[1]++;
			}
		}

		if (min(occ[0],occ[1]) == 1){
			int o = dif[0];
			if (occ[1] == 1)o=dif[1];
			if (V[1].f-V[0].f == o){cout<<V[0].s;return 0;}
			if (V[SZ(V)-1].f -V[SZ(V)-2].f==o){cout<<V.back().s;return 0;}
			if (o == 0){
				for (int i=0;i<N-1;++i){
					if (V[i+1].f==V[i].f){
						cout<<V[i].s;
						return 0;
					}
				}
			}
			cout<<-1;return 0;
		}
		// cout<<dif[0]<<' '<<dif
		if (min(occ[0],occ[1]) == 2){
			int a=-1;
			int b=-1;
			int o = dif[0];
			if (occ[0] != 2){cout<<-1;return 0;}
			if (dif[0]*2!=dif[1]){cout<<-1;return 0;}

			for (int i=0;i<N-1;++i){
				int d = V[i+1].f-V[i].f;
				if (d == o){
					if (a != -1)b = i;
					else a = i;
				}
			}
			if (abs(a-b) == 1){cout<<V[min(a,b)+1].s;return 0;}
			cout<<-1;return 0;
		}

	}
	cout<<-1;return 0;
}