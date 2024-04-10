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

string t;
string go(string &s,string &v){
	string res=s;
	string rem=s;
	for(char c:v){
		string nr;
		for(char x:rem){
			if(x==c)continue;
			else{
				res+=x;
				nr+=x;
			}
		}
		rem=nr;
	}
	return res;
}
void solve(){
	cin>>t;
	string v;
	bitset<26> chk;
	Vi cnt(26);
	int n=t.length();
	fdn(i,n-1,0,1){
		cnt[t[i]-'a']++;
		if(!chk[t[i]-'a']){
			v+=t[i];
			chk[t[i]-'a']=1;
		}
	}
	Vi vv;
	int s=0;
	reverse(ALL(v));
	int N=v.size();
	fup(j,0,N-1,1){
		if(cnt[v[j]-'a']%(j+1)){
			cout<<"-1\n";
			return;
		}
		vv.pb(cnt[v[j]-'a']/(j+1));
		s+=vv.back();
	}
	string ss=string(t.begin(),t.begin()+s);
	string tt=go(ss,v);
	if(tt!=t){
		cout<<"-1\n";
		return;
	}
	cout<<ss<<' '<<v<<endl;
}
int main() {
	SYNC;
	int tc;
	cin>>tc;
	while(tc--)solve();
}