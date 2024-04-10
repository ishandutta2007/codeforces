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

int n;
char s[100005];
int cnt[26];
void solve(){
	MEM0(cnt);
	scanf("%s",s);
	n=strlen(s);
	fup(i,0,n-1,1)cnt[s[i]-'a']++;
	vector<Pi> v;
	fup(i,0,25,1){
		if(cnt[i]>0)v.pb(mp(i,cnt[i]));
	}
	if(v.size()==1){
		for(auto [x,y]:v){
			while(y--)putchar(x+'a');
		}
		puts("");
		return;
	}
	int mn=INF;
	for(auto [x,y]:v)mn=min(mn,y);
	if(mn==1){
		fup(i,0,(int)v.size()-1,1){
			if(v[i].Y==1){
				putchar(v[i].X+'a');
				v[i].Y--;
				break;
			}
		}
		fup(i,0,(int)v.size()-1,1){
			while(v[i].Y--){
				putchar(v[i].X+'a');
			}
		}
		puts("");
		return;
	}
	if(v[0].Y<=n/2+1){
		putchar(v[0].X+'a');
		putchar(v[0].X+'a');
		v[0].Y-=2;
		fup(i,1,(int)v.size()-1,1){
			while(v[i].Y--){
				putchar(v[i].X+'a');
				if(v[0].Y>0){
					putchar(v[0].X+'a');
					v[0].Y--;
				}
			}
		}
		puts("");
		return;
	}
	if(v.size()==2){
		putchar(v[0].X+'a');
		while(v[1].Y--){
			putchar(v[1].X+'a');
		}
		v[0].Y--;
		while(v[0].Y--){
			putchar(v[0].X+'a');
		}
		puts("");
		return;
	}else{
		putchar(v[0].X+'a');
		putchar(v[1].X+'a');
		v[1].Y--;
		v[0].Y--;
		while(v[0].Y--){
			putchar(v[0].X+'a');
		}
		putchar(v[2].X+'a');
		v[2].Y--;
		fup(i,1,(int)v.size()-1,1){
			while(v[i].Y--){
				putchar(v[i].X+'a');
			}
		}
		puts("");
		return;
	}
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}