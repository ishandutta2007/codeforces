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
#define INF 987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
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
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int parent[100001];
int enemy[100001];
map<string,int> M;
int find(int a)
{
	if (parent[a] < 0)return a;
	return parent[a] = find(parent[a]);
}
void merge(int a, int b)
{
	a = find(a), b = find(b);
	if (a != b)
	{
		parent[a] += parent[b];
		parent[b] = a;
	}
}
int main() {
	MEM_1(parent);
	MEM_1(enemy);
	SYNC;
	int n,m,q;
	cin>>n>>m>>q;
	string s,t;
	fup(i,0,n-1,1)
	{
		cin>>s;
		M[s]=i;
	}
	fup(i,1,m,1)
	{
		int tt,a,b;
		cin>>tt>>s>>t;
		a=M[s],b=M[t];
		a=find(a),b=find(b);
		if(tt==1)
		{
			if (enemy[a] == b)
				cout<<"NO"<<'\n';
			else
			{
				cout<<"YES"<<'\n';
				if(a==b)continue;
				if(enemy[a]==-1 && enemy[b]==-1) merge(a, b);
				else if (enemy[a] != -1 && enemy[b] == -1)merge(a, b);
				else if (enemy[a] == -1 && enemy[b] != -1)merge(b, a);
				else
				{
					merge(a, b);
					merge(enemy[a], enemy[b]);
				}
			}
		}
		else
		{
			if(a==b)cout<<"NO"<<'\n';
			else
			{
				cout<<"YES"<<'\n';
				if(enemy[a]==-1 && enemy[b]==-1)
				{
					enemy[a] = b;
					enemy[b] = a;
				}
				else if (enemy[a] == -1 && enemy[b] != -1)
					merge(enemy[b], a);
				else if(enemy[a]!=-1 && enemy[b]==-1)
					merge(enemy[a], b);
				else
				{
					merge(a, enemy[b]);
					merge(enemy[a], b);
				}
			}
		}
	}
	while(q--)
	{
		cin>>s>>t;
		int a,b;
		a=M[s],b=M[t];
		a=find(a),b=find(b);
		if(a==b)cout<<"1"<<'\n';
		else if(enemy[a]==b)cout<<"2"<<'\n';
		else cout<<"3"<<'\n';
	}
}