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

char s[1005];
string ss;
int t,k;
struct node {
	bool valid;
	int child[9], pi;
	node(){
		valid = 0;
		MEM_1(child);
		pi = -1;
	}
};
vector<node> trie;
int init(){
	node x;
	trie.push_back(x);
	return (int)trie.size() - 1;
}
void add(int n, string &s, int i){
	if (i == s.length()){
		trie[n].valid = 1;
		return;
	}
	int c = s[i] - '1';
	if (trie[n].child[c] == -1){
		int next = init();
		trie[n].child[c] = next;
	}
	add(trie[n].child[c], s, i + 1);
}
void dfs(int K){
	if(K&t)return;
	if(K&(1<<k)){
		add(0,ss,0);
		return;
	}
	int b=31-__builtin_clz(K);
	fup(i,1,9,1){
		if(b+i<=k){
			ss+=i+'0';
			dfs(K|(K<<i));
			ss.pop_back();
		}
	}
}
int d[1000][5000],nn;
int go(int N,int node){
	if(trie[node].valid)return INF;
	if(N==nn)return 0;
	int &ret=d[N][node];
	if(~ret)return ret;
	ret=1+go(N+1,node);
	int c=s[N]-'1';
	int nd=node;
	while(nd!=0 && trie[nd].child[c]==-1)nd=trie[nd].pi;
	if(trie[nd].child[c]!=-1)nd=trie[nd].child[c];
	ret=min(ret,go(N+1,nd));
	return ret;
}
int main(){
	MEM_1(d);
	init();
	scanf("%s%d",s,&k);
	nn=strlen(s);
	fup(i,1,k-1,1){
		if(k%i==0)t|=1<<i;
	}
	dfs(1);
	trie[0].pi = 0;
	queue<int> q;
	q.push(0);
	while (!q.empty()){
		int x = q.front();
		q.pop();
		fup(i, 0, 8, 1){
			int next = trie[x].child[i];
			if (next == -1)continue;
			if (x == 0)trie[next].pi = 0;
			else{
				int t = trie[x].pi;
				while (t != 0 && trie[t].child[i] == -1) {
					t = trie[t].pi;
				}
				if (trie[t].child[i] != -1) {
					t = trie[t].child[i];
				}
				trie[next].pi = t;
			}
			int pi = trie[next].pi;
			trie[next].valid |= trie[pi].valid;
			q.push(next);
		}
	}
	printf("%d\n",go(0,0));
}