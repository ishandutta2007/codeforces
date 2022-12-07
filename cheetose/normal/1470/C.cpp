#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 987654321987654321
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
typedef pair<db, db> Pd;
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
const int MOD = 1000000021;
ll POW(ll a, ll b, ll MMM=MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

int a[30],b[30];
void solve(){
	int n=6,p=0,k=4;
	fup(i,0,n-1,1)a[i]=k;
	fup(i,0,n-1,1)printf("%d ",a[i]);
	puts("");
	fup(K,1,20,1){
		MEM0(b);
		fup(i,0,n-1,1){
			int l=(i+n-1)%n,r=(i+1)%n;
			if(i!=p)b[l]+=a[i]/2,b[r]+=(a[i]+1)/2;
			else b[r]+=a[i];
		}
		memcpy(a,b,sizeof(b));
		fup(i,0,n-1,1)printf("%d ",a[i]);
		puts("");
	}
}
int main() {
	SYNC;
	int n,k;
	cin>>n>>k;
	if(n<=1800){
		int x;
		fup(i,1,901,1){
			cout<<"? 1"<<endl;
			cin>>x;
		}
		int now=0;
		fdn(i,10,0,1){
			cout<<"? "<<now+1<<endl;
			cin>>x;
			if(x==k){
				if(n&1){
					cout<<"? "<<now+1<<endl;
					cin>>x;
					if(x==k){
						cout<<"! "<<now+1<<endl;
						return 0;
					}
				}else{
					int tmp=(now+1)%n;
					cout<<"? "<<tmp+1<<endl;
					cin>>x;
					if(x>k)cout<<"! "<<now+1<<endl;
					else{
						now=(now+n/2)%n;
						cout<<"! "<<now+1<<endl;
					}
					return 0;
				}
			}
			if(x>k)now=(now+n*2000-(1<<i))%n;
			else now=(now+(1<<i))%n;
		}
		cout<<"! "<<now+1<<endl;
		return 0;
	}
	int x;
	fup(i,1,301,1){
		cout<<"? 1"<<endl;
		cin>>x;
	}
	Vi v;
	fup(i,0,n-1,300){
		cout<<"? "<<i+1<<endl;
		cin>>x;
		if(x!=k)v.pb(i);
	}
	int dif=(v[0]-v.back()+n)%n,w=0;
	fup(i,1,(int)v.size()-1,1){
		int t=v[i]-v[i-1];
		if(t>dif){
			dif=t,w=i;
		}
	}
	rotate(v.begin(),v.begin()+w,v.end());
	int l=v[0],r=v.back();
	if(l>r)r+=n;
	while(l<=r){
		int t=l+r>>1;
		int tt=t%n;
		cout<<"? "<<tt+1<<endl;
		cin>>x;
		if(x==k){
			cout<<"! "<<tt+1<<endl;
			return 0;
		}
		if(x>k)r=t-1;
		else l=t+1;
	}
}