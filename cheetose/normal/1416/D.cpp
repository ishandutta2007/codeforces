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
#define MEM0(a) memset((a),0,sizeof(a));
#define MEM_1(a) memset((a),-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
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
typedef vector<db> Vd;
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

int parent[200001],sz[200001];
set<int> S[200001];
Pi p[300001],query[500000];
VPi info;
int find(int x){
	if(x==parent[x])return x;
	return find(parent[x]);
}
void merge(int a,int b){
	a=find(a),b=find(b);
	if(a==b){
		info.pb({0,0});
		return;
	}
	if(sz[a]>sz[b])swap(a,b);
	info.pb({a,b});
	sz[b]+=sz[a];
	parent[a]=b;
	for(auto it=S[a].begin();it!=S[a].end();it++){
		S[b].insert(*it);
	}
}
void rollback(){
	auto [a,b]=info.back();
	info.pop_back();
	if(a==0 && b==0)return;
	sz[b]-=sz[a];
	parent[a]=a;
	for(auto it=S[a].begin();it!=S[a].end();){
		auto it2=S[b].find(*it);
		if(it2!=S[b].end()){
			S[b].erase(it2);
			it++;
		}else{
			it=S[a].erase(it);
		}
	}
}
bool cc[300001];
int main() {
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	fup(i,1,n,1){
		int x;
		scanf("%d",&x);
		S[i].insert(x);
		parent[i]=i,sz[i]=1;
	}
	fup(i,1,m,1)scanf("%d%d",&p[i].X,&p[i].Y);
	fup(i,0,q-1,1){
		scanf("%d%d",&query[i].X,&query[i].Y);
		if(query[i].X==2)cc[query[i].Y]=1;
	}
	fup(i,1,m,1)if(!cc[i])merge(p[i].X,p[i].Y);
	fdn(i,q-1,0,1){
		if(query[i].X==2){
			int j=query[i].Y;
			merge(p[j].X,p[j].Y);
		}
	}
	fup(i,0,q-1,1){
		int j=query[i].Y;
		if(query[i].X==1){
			j=find(j);
			if(S[j].empty()){
				puts("0");
			}else{
				auto it=S[j].end();
				it--;
				printf("%d\n",*it);
				S[j].erase(it);
			}
		}else{
			rollback();
		}
	}
}