//cwystc <-->   --by cwy
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const double PI=acos(-1);
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define per(i,a,b) for (int i=(a);i>=(b);i--)
#define Rep(i,a,b) for (int i=(a);i<(b);i++)
#define Per(i,a,b) for (int i=(a);i>(b);i--)
#define travel_set(it,a) for (set<int>::iterator (it)=(a).begin();(it)!=(a).end();(it)++)
#define travel_map(it,a) for (map<int>::iterator (it)=(a).begin();(it)!=(a).end();(it)++)
#define travel_vec(it,a) for (vector<int>::iterator (it)=(a).begin();(it)!=(a).end();(it)++)
#define p(x) cout << x << endl;
#define def cout << "find" << endl;
#define what_is(x) cout << #x << " is " << x << endl;
template <class T>T sqr(T x){return x*x;}
template <class T>T alex(T x){return (x>0)?x:-x;}
template <class T>void read(T&x){
	x=0;T f=1;char ch=getchar();
	while ((ch<48||ch>57)&&ch!=45)ch=getchar();
	if (ch==45)f=-1,ch=getchar();
	while (ch>=48&&ch<=57)x=x*10+ch-48,ch=getchar();
	x*=f;
}

//-------------------------------------------------head-------------------------------------------------

#define maxn 55
#define eps 1e-9
int n,a[maxn],b[maxn];
double f[maxn][maxn];vector<pair<int,double> >vec;
double sum[maxn];
bool check(double mid){
	vec.clear();rep(i,1,n)vec.pb(mp(a[i],mid*b[i]-a[i]));sort(vec.begin(),vec.end());
	vec.pb(mp(0,0));reverse(vec.begin(),vec.end());
	// Rep(i,0,vec.size())printf("(%d %lf)",vec[i].fi,vec[i].se);puts("");
	memset(f,233,sizeof(f));double inf=f[0][0];f[0][0]=0.0;
	// cerr << inf << endl;
	rep(i,1,n){
		int _=i;sum[0]=0.0;while (_<=n&&vec[i].fi==vec[_].fi)sum[_-i+1]=sum[_-i]+vec[_].se,_++;
		// cerr << i << " " << _ << endl;
		// rep(j,0,_-i)cerr << sum[j] << " ";cerr << endl;
		Rep(j,0,i)if (f[i-1][j]!=inf){
			// cerr << i << " " << j << " " << f[i-1][j] << endl;
			for (int k=0;k<=min(j,_-i);k++){
				int tmp=_-i-k;f[_-1][j+tmp-k]=max(f[_-1][j+tmp-k],f[i-1][j]+sum[tmp]);
			}
		}
		i=_-1;
	}
	rep(i,0,n)if (f[n][i]>=0.0)return /*cerr << n << " " << i << "  " << f[n][i] << endl,*/true;
	return false;
}
int main(){
	read(n);
	rep(i,1,n)read(a[i]);
	rep(i,1,n)read(b[i]);
	double l=0.0,r=1e8;
	rep(rp,1,1111){
		double mid=(l+r)/2.0;
		if (check(mid))r=mid;else l=mid;
	}
	printf("%lld\n",(ll)(ceil(l*1000)));
	return 0;
}