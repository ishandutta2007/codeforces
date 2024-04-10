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
const int MAXN = 100100;

struct ConvexHull{
	deque<pi> dq;
	ConvexHull(){}
	double intersect (pi a, pi b){
		return (double)(b.s - a.s)/(a.f-b.f);
	}
	void insert(pi cur){
		while (SZ(dq) > 1){
			if (intersect(dq[SZ(dq) - 1], cur) <= intersect(dq[SZ(dq)-2], cur))dq.pop_back();
			else break;
		}
		dq.pb(cur);
	}
	ll query(ll xc){
		while (SZ(dq) > 1){
			if (dq[0].f*xc + dq[0].s >= dq[1].f*xc+dq[1].s)dq.pop_front();
			else break;
		}
		return dq[0].f*xc+dq[0].s;
	}
}*H;

int N;
int A[MAXN];
int B[MAXN];
ll dp[MAXN];

int main(){
	cin>>N;
	for (int i=1;i<=N;++i)cin>>A[i];
	for (int i=1;i<=N;++i)cin>>B[i];
	H = new ConvexHull();
	dp[1] = 0;
	H->insert(mp(B[1], dp[1]));
	for (int i=2;i<=N;++i){
		dp[i] = H->query(A[i]);
		// cout<<"inserting "<<B[i]<<' '<<dp[i]<<'\n';
		H->insert(mp(B[i], dp[i]));
		// cout<<dp[i]<<' ';
	}
	cout<<dp[N];
}