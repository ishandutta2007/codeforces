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
const int MOD = 1000000021;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

bool chk[100005];
string s,t[100000];
Vi vv[100000];
int k[100000];
int num[100005],cc;
vector<int> V[700];
struct aho_corasick{
	int len;
	vector<Vi> trie;
	Vi fail,term;
	int piv; // trie
	void init(vector<int> &v){
		int N=v.size();
		trie.resize(N*len+1);
		fup(i,0,(int)trie.size()-1,1)trie[i].resize(26);
		fail.resize(N*len+1);
		term.resize(N*len+1,-1);
		for(auto &i: v)for(auto &j: t[i])j=j-'a';// lowercase
		piv = 0;
		for(auto &i : v){
			int p = 0;
			for(auto &j : t[i]){
				if(!trie[p][j]) trie[p][j] = ++piv;
				p = trie[p][j];
			}
			term[p] = i;
		}
		queue<int> que;
		for(int i=0; i<26; i++)
			if(trie[0][i]) que.push(trie[0][i]);
		while(!que.empty()){
			int x = que.front();
			que.pop();
			for(int i=0; i<26; i++){
				if(trie[x][i]){
					int p = fail[x];
					while(p && !trie[p][i]) p = fail[p];
					p = trie[p][i];
					fail[trie[x][i]] = p;
					que.push(trie[x][i]);
				}
			}
		}
	}
	void query(string &s){
		int p = 0;
		for(int i=0;i<s.length();i++){
			int c=s[i];
			while(p && !trie[p][c]) p = fail[p];
			p = trie[p][c]; 
			if(term[p]!=-1){
				vv[term[p]].pb(i);
				p=fail[p];
			}
		}
	}
}aho_corasick[700];
int main(){
	MEM_1(num);
	SYNC;
	cin>>s;
	int n=s.length();
	for(auto &i:s)i-='a';
	int m;
	cin>>m;
	fup(i,0,m-1,1){
		cin>>k[i]>>t[i];
		if(num[t[i].length()]==-1){
			aho_corasick[cc].len=t[i].length();
			num[t[i].length()]=cc++;
		}
		V[num[t[i].length()]].emplace_back(i);
	}
	fup(i,0,cc-1,1){
		aho_corasick[i].init(V[i]);
		aho_corasick[i].query(s);
	}
	fup(i,0,m-1,1){
		if(vv[i].size()<k[i])cout<<"-1\n";
		else{
			int ans=INF;
			sort(ALL(vv[i]));
			k[i]--;
			fup(j,k[i],(int)vv[i].size()-1,1){
				ans=min(ans,vv[i][j]-vv[i][j-k[i]]);
			}
			cout<<ans+t[i].length()<<'\n';
		}
	}
}