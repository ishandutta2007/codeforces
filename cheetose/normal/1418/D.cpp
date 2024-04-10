#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 1000000005
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
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

int n,q;
int a[100000],o[100000],x[100000];
set<int> S;
priority_queue<iii> sub;
priority_queue<int> q1;
priority_queue<int,Vi,greater<int>> q2;
int res(){
	while(!q1.empty()){
		int x=q1.top();
		if(S.find(x)==S.end())q1.pop();
		else break;
	}
	while(!q2.empty()){
		int x=q2.top();
		if(S.find(x)==S.end())q2.pop();
		else break;
	}
	while(!sub.empty()){
		auto [dif,x,y]=sub.top();
		if(S.find(x)==S.end() || S.find(y)==S.end())sub.pop();
		else if(*S.upper_bound(x)!=y)sub.pop();
		else break;
	}
	if(q1.size()<=2)return 0;
	return q1.top()-q2.top()-get<0>(sub.top());
}
void add(int x){
	q1.push(x);q2.push(x);
	auto it=S.lower_bound(x);
	if(it!=S.end()){
		sub.push(iii((*it)-x,x,*it));
	}
	if(it!=S.begin()){
		it--;
		sub.push(iii(x-(*it),*it,x));
	}
	S.insert(x);
}
int main(){
	scanf("%d%d",&n,&q);
	fup(i,0,n-1,1){
		int x;
		scanf("%d",&x);
		add(x);
	}
	printf("%d\n",res());
	fup(i,0,q-1,1){
		int o,x;
		scanf("%d%d",&o,&x);
		if(o==0){
			auto it=S.find(x);
			auto it2=it;
			it2++;
			if(it!=S.begin() && it2!=S.end()){
				it--;
				sub.push(iii((*it2)-(*it),(*it),(*it2)));
			}
			S.erase(x);
		}
		else add(x);
		printf("%d\n",max(0,res()));
	}
}