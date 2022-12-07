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

int d[505],par[505];
bool chk[505];
int main(){
	MEM_1(d);
	SYNC;
	int n,k;
	cin>>n>>k;
	d[n]=0;
	queue<int> q;
	q.push(n);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		int rem=n-x;
		fup(i,abs(x-k),n-abs(n-x-k),2){
			if(d[i]==-1){
				d[i]=d[x]+1;
				q.push(i);
				par[i]=x;
			}
		}
	}
	if(d[0]==-1){
		cout<<-1<<endl;
		return 0;
	}
	int now=0,s=0;
	while(now!=n){
		int next=par[now];
		int NEW=(next-now+k)/2,DEL=(k-next+now)/2;
		Vi t;
		fup(i,1,n,1){
			if(NEW>0 && chk[i]==0){
				t.pb(i);
				NEW--;
			}
		}
		fup(i,1,n,1){
			if(DEL>0 && chk[i]==1){
				t.pb(i);
				DEL--;
			}
		}
		cout<<"? ";
		for(int x:t)cout<<x<<' ';
		cout<<endl;
		int x;
		cin>>x;
		s^=x;
		for(int x:t)chk[x]^=1;
		now=next;
	}
	cout<<"! "<<s<<endl;
}