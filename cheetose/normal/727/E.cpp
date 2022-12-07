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
#define INF 98765432198765321
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
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

string s,t;
const ll MOD1=1000000009,MOD2=1000000021;
ll h1[2000002],h2[2000002];
ll pow1[1000001],pow2[1000001];
Pll th[100001];
Pll HASH(int l,int r)
{
	l++,r++;
	int leng=r-l+1;
	return mp((h1[r]-pow1[leng]*h1[l-1]+MOD1*MOD1)%MOD1,(h2[r]-pow2[leng]*h2[l-1]+MOD2*MOD2)%MOD2);
}
pair<Pll,int> P[100000];
bool chk[100000];
int main() {
	pow1[0]=pow2[0]=1;
	fup(i,1,1000000,1)pow1[i]=(pow1[i-1]*31)%MOD1,pow2[i]=(pow2[i-1]*37)%MOD2;
	SYNC;
	int n,m,k;
	cin>>n>>k;
	cin>>s;
	s+=s;
	fup(i,1,2*n*k,1)
	{
		h1[i]=(h1[i-1]*31+s[i-1]-'a'+1)%MOD1;
		h2[i]=(h2[i-1]*37+s[i-1]-'a'+1)%MOD2;
	}
	cin>>m;
	fup(i,0,m-1,1)
	{
		cin>>t;
		th[i]=mp(t[0]-'a'+1,t[0]-'a'+1);
		fup(j,1,k-1,1)
		{
			th[i].X=(th[i].X*31+t[j]-'a'+1)%MOD1;
			th[i].Y=(th[i].Y*37+t[j]-'a'+1)%MOD2;
		}
		P[i]=mp(th[i],i+1);
	}
	sort(P,P+m);
	fup(i,0,k-1,1)
	{
		queue<int> q;
		bool ok=1;
		fup(l,i,2*n*k-1,k)
		{
			if(q.size()==n)break;
			int r=l+k-1;
			Pll p=HASH(l,r);
			int t=lower_bound(P,P+m,mp(p,-1))-P;
			if(t<m && P[t].X==p && !chk[t])
			{
				chk[t]=1;
				q.push(t);
			}
			else
			{
				ok=0;
				while(!q.empty())
				{
					chk[q.front()]=0;
					q.pop();
				}
				break;
			}
		}
		if(ok)
		{
			cout<<"YES\n";
			while(!q.empty())
			{
				cout<<P[q.front()].Y<<' ';
				q.pop();
			}
			return 0;
		}
	}
	cout<<"NO\n";
}