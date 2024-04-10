#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<cstring>
#include<complex>
#include<cmath>
#include<algorithm>
#include<list>
#include<functional>
#define mp make_pair
#define X first
#define Y second
#define INF 987654321
#define PI 3.14159265358979323846264
#define MOD 1000000007
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef pair<double, double> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<double> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef complex<double> base;
ll POW(ll a, ll b) { if (b == 0)return 1; if (b == 1)return a; if (b & 1)return (a*POW(a, b - 1)) % MOD; ll t = POW(a, b / 2); return (t*t) % MOD; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

set<int> S[62];
set<int>::iterator it,it1,it2;
int tree[524288];
char s[200001];
bool chk[200001];
void init(int node, int S, int E)
{
	if (S == E)
	{
		tree[node] = 1;
		return;
	}
	init(2 * node, S, (S + E) / 2);
	init(2 * node + 1, (S + E) / 2 + 1, E);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int find(int node, int S, int E, int k)
{
	if (S == E)return S;
	if (k <= tree[node*2])return find(node * 2, S, (S + E) / 2, k);
	return find(node * 2 + 1, (S + E) / 2 + 1, E, k - tree[node * 2]);
}
void update(int node, int S, int E, int k)
{
	tree[node]--;
	if (S == E)return;
	if (k <= (S + E) / 2) update(node * 2, S, (S + E) / 2, k);
	else update(node * 2 + 1, (S + E) / 2 + 1, E, k);
}
inline int ctoi(char c)
{
	if (c >= '0' && c <= '9')return c - '0';
	if (c >= 'a' && c <= 'z')return c - 'a' + 10;
	if (c >= 'A'&&c <= 'Z')return c - 'A' + 36;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	init(1, 1, n);
	scanf("%s", s);
	fup(i, 0, n - 1, 1)
		S[ctoi(s[i])].insert(i + 1);
	while (m--)
	{
		int l, r;
		char c;
		scanf("%d %d %c\n", &l, &r,&c);
		int cc = ctoi(c);
		int nl = find(1, 1, n, l);
		int nr = find(1, 1, n, r);
		it1 = S[cc].lower_bound(nl);
		it2 = S[cc].upper_bound(nr);
		Vi a;
		for (it=it1; it!=it2; it++)
			a.push_back(*it);
		S[cc].erase(it1, it2);
		for (int k : a)
		{
			update(1, 1, n, k);
			chk[k] = 1;
		}
	}
	fup(i, 1, n, 1)
		if (!chk[i])printf("%c", s[i - 1]);
}