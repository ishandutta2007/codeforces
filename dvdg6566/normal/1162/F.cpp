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
#define SZ(x) (int)x.size()
#define f first
#define s second
#define MAXN 2010
ll MOD = 998244353;

string S;
int N;
int cons[MAXN];
queue<int> Q;
int p[MAXN];
int tot_islands;
ll ans;
ll M2[MAXN];

int par(int x){return (p[x] == x)?x:p[x] = par(p[x]);}
void merge(int a, int b){
	a=par(a);b=par(b);
	if (a == b)return;
	tot_islands--;
	p[a] = b;
}

int main(){
	cin>>S;N=SZ(S);
	M2[0] = 1;
	for (int i=1;i<=2*N;++i){
		M2[i] = (M2[i-1]*2)%MOD;
	}
	reverse(ALL(S));
	S = '0' + S;
	for (int len = 1;len<= N;++len){
		tot_islands=0;
		for (int i=1;i<=2*N;++i)p[i] = i;

		while(SZ(Q))Q.pop();
		// Firstly start fixing positions
		memset(cons, -1, sizeof(cons));
		for (int i=len+1;i<=N;++i){
			cons[N+i] = 0;
			Q.push(N+i);
		}
		cons[N] = 1;
		Q.push(N);
		cons[len+N] = 1;
		Q.push(len+N);
		bool fail = 0;
		while (SZ(Q)){
			int t = Q.front();Q.pop();
			// cout<<"T "<<t<<'\n';
			int side = (t-1)/N;
			int ind = t%N; if (ind==0)ind=N;
			// cout<<side<<' '<<ind<<'\n';
			if (side == 0){
				int opp = N+1-ind;
				if (cons[opp] == -1){cons[opp] = cons[t];Q.push(opp);}
				else if (cons[opp] != cons[t]){fail = 1;break;}
				int o2 = ind+N;
				if (S[ind] == '?')continue;
				int c=S[ind]-'0';
				if (cons[o2] == -1){cons[o2] = c^cons[t]; Q.push(o2);}
				if ((cons[o2] ^cons[t]) == c)continue;
				fail=1;break;
			}else{
				if (ind <= len){
					int opp=N+(len+1-ind);
					if (cons[opp] == -1){cons[opp] = cons[t];Q.push(opp);}
					else if (cons[opp] != cons[t]){fail = 1;break;}
				}
				int o2 = ind;
				if (S[ind] == '?')continue;
				int c=S[ind]-'0';
				if (cons[o2] == -1){cons[o2] = c^cons[t]; Q.push(o2);}
				if ((cons[o2] ^cons[t]) == c)continue;
				fail=1;break;
			}
		}
		// for (int i=1;i<=N;++i)cout<<cons[i]<<' ';cout<<'\n';
		// for (int j=1;j<=N;++j)cout<<cons[j+N]<<' ';cout<<'\n';
		if (fail == 1)continue;
		for (int i=1;i<=2*N;++i){
			if (cons[i] != -1)continue;
			++tot_islands;
			int side = (i-1)/N;
			int ind = i%N; if (ind==0)ind=N;
			if (side == 0){
				merge(i, N+1-ind);
				if (S[ind] != '?')merge(i, ind+N);
			}else{
				if (S[ind] != '?')merge(i, ind);
				if (ind <= len)merge(i, N+len+1-ind);
			}
		}
		// cout<<"Length "<<len<<" tot "<<tot_islands<<'\n';
		ans += M2[tot_islands];
		ans %= MOD;
		// break;
	}
	cout<<ans;
}