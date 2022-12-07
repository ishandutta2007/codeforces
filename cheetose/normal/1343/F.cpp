#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset((a),0,sizeof(a))
#define MEM_1(a) memset((a),-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define COMPRESS(a) sort(ALL(a));a.resize(unique(ALL(a))-a.begin())
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef pair<ld, ld> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<ld> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

int ans[202],b[202];
bool chk[202];
void solve(){
	int n;
	scanf("%d",&n);
	vector<set<int>> S;
	fup(i,1,n-1,1){
		int k;
		scanf("%d",&k);
		set<int> s;
		while(k--){
			int x;
			scanf("%d",&x);
			s.insert(x);
		}
		S.emplace_back(s);
	}
	fup(t,1,n,1){
		bool ok=1;
		auto T=S;
		ans[1]=t;
		queue<int> q;
		for(auto &s:T){
			if(s.find(t)!=s.end()){
				s.erase(t);
				if(s.size()==1){
					q.push(*s.begin());
				}
			}
		}
		if(q.size()!=1)continue;
		fup(i,2,n,1){
			int x=q.front();
			q.pop();
			ans[i]=x;
			for(auto &s:T){
				if(s.find(x)!=s.end()){
					s.erase(x);
					if(s.size()==1){
						q.push(*s.begin());
					}
				}
			}
			if(i<n && q.size()!=1){
				ok=0;
				break;
			}
		}
		if(ok){
			MEM0(chk);
			fup(i,1,n,1)b[ans[i]]=i;
			for(auto &s:S){
				int l=n+1,r=0;
				for(int x:s){
					l=min(l,b[x]);
					r=max(r,b[x]);
				}
				if(chk[r] || r-l+1!=s.size()){
					ok=0;
					break;
				}
				chk[r]=1;
			}
			if(ok){
				fup(i,1,n,1)printf("%d ",ans[i]);
				puts("");
				return;
			}
		}
	}
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}