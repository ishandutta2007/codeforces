#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<string>
#include<stack>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<cstring>
#include<complex>
#include<cmath>
#include<iomanip>
#include<numeric>
#include<algorithm>
#include<list>
#include<functional>
#include<cassert>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 1987654321
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
typedef vector<double> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int,int,int,int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

string s,t,tt;
int cnt[200002],invcnt[200002];
int n,m;
struct node {
	int valid;
	int child[26];
	node()
	{
		valid = 0;
		MEM_1(child);
	}
};
struct Trie{
	vector<node> trie;
	int init()
	{
		node x;
		trie.push_back(x);
		return (int)trie.size() - 1;
	}
	void add(int n, string &s, int i)
	{
		if (i == s.length())
		{
			trie[n].valid++;
			return;
		}
		int c = s[i] - 'a';
		if (trie[n].child[c] == -1)
		{
			int next = init();
			trie[n].child[c] = next;
		}
		add(trie[n].child[c], s, i + 1);
	}
}tr,inv;

void getkmp(string &s,string &p,bool inv)
{
	int m=p.length();
	Vi pi(m+1);
	for (int i = 1, j = 0; i < m; i++)
	{
		while (j > 0 && p[i] != p[j]) j = pi[j - 1];
		if (p[i] == p[j]) pi[i] = ++j;
	}
	for (int i = 0, j = 0; i < n; i++)
	{
		while (j > 0 && s[i] != p[j]) j = pi[j-1];
		if (s[i] == p[j])
		{
			if (j == m - 1)
			{
				if(!inv)cnt[i-m+1]++;
				else invcnt[i-m+1]++;
				j=pi[j];
			}
			else j++;
		}
	}
}
int main() {
	SYNC;
	int N;
	cin>>t>>N;
	n=t.length();
	tt=t;
	reverse(ALL(tt));
	tr.init();inv.init();
	fup(i,0,N-1,1)
	{
		cin>>s;
		if(s.length()<=400)
		{
			tr.add(0,s,0);
			reverse(ALL(s));
			inv.add(0,s,0);
		}
		else
		{
			getkmp(t,s,0);
			reverse(ALL(s));
			getkmp(tt,s,1);
		}
	}
	fup(i,0,n-1,1)
	{
		int now=0,j=i;
		while(now!=-1)
		{
			cnt[i]+=tr.trie[now].valid;
			if(j==n)break;
			now=tr.trie[now].child[t[j++]-'a'];
		}
		now=0,j=i;
		while(now!=-1)
		{
			invcnt[i]+=inv.trie[now].valid;
			if(j==n)break;
			now=inv.trie[now].child[tt[j++]-'a'];
		}
	}
	reverse(invcnt,invcnt+n);
	ll ans=0;
	fup(i,0,n-2,1)
		ans+=1LL*invcnt[i]*cnt[i+1];
	cout<<ans;
}