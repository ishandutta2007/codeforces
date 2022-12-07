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

vector<int> suffixarray(string& in) {
	int n = (int)in.size(), c = 0;
	vector<int> temp(n), pos2bckt(n), bckt(n), bpos(n), out(n);
	for(int i=0; i<n; i++) out[i] = i;
	sort(out.begin(), out.end(),
		 [&](int a, int b){return in[a] < in[b];});
	for(int i=0; i<n; i++) {
		bckt[i] = c;
		if (i + 1 == n || in[out[i]] != in[out[i+1]]) c++;
	}
	for (int h = 1; h < n && c < n; h <<= 1) {
		for (int i=0; i<n; i++) pos2bckt[out[i]] = bckt[i];
		for (int i=n-1; i>=0; i--) bpos[bckt[i]] = i;
		for (int i=0; i<n; i++) if (out[i] >= n-h)
			temp[bpos[bckt[i]]++] = out[i];
		for (int i=0; i<n; i++) if (out[i] >= h)
			temp[bpos[pos2bckt[out[i]-h]]++] = out[i] - h;
		c = 0;
		for (int i = 0; i + 1 < n; i++) {
			int a = (bckt[i] != bckt[i+1]) || (temp[i] >= n-h) || (pos2bckt[temp[i+1]+h] != pos2bckt[temp[i]+h]);
			bckt[i] = c; c += a;
		}
		bckt[n-1] = c++;
		temp.swap(out);
	}
	return out;
}
vector<int> lcparray(string& in, vector<int>& sa) {
	int n = (int)in.size();
	if (n == 0) return vector<int>();
	vector<int> rank(n), height(n - 1);
	for(int i=0; i<n; i++) rank[sa[i]] = i;
	for(int i=0, h=0; i<n; i++){
		if(rank[i] == 0) continue;
		int j = sa[rank[i]-1];
		while (i+h < n && j+h < n && in[i+h]==in[j+h]) h++;
		height[rank[i]-1] = h;
		if (h > 0) h--;
	}
	return height;
}
char t[5005];
int a[5005];
int d[5005],mn[5005][5005];
void solve(){
	int n;
	scanf("%d%s",&n,t);
	string s=t;
	auto sa=suffixarray(s);
	auto lcp=lcparray(s,sa);
	fup(i,0,n-1,1)a[sa[i]+1]=i;
	fup(i,0,n-2,1){
		mn[i][i+1]=lcp[i];
		fup(j,i+2,n-1,1){
			mn[i][j]=min(mn[i][j-1],lcp[j-1]);
		}
	}
	fup(i,1,n,1){
		d[i]=n+1-i;
		fup(j,1,i-1,1){
			if(a[i]>a[j]){
				d[i]=max(d[i],d[j]+n+1-i-mn[a[j]][a[i]]);
			}
		}
	}
	printf("%d\n",*max_element(d,d+n+1));
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}