#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
#define range(x) (x).begin(),(x).end()
std::mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int sj(int n)
{
	unsigned int x=rnd();
	return x%n+1;
}
#define rand fst
const int inf=1e9;
priority_queue<int> ONLYYFORRCOPYY;
priority_queue<int,vector<int>,greater<int> > ONLYYFORRCOPYY__;
struct Q
{
	int u,v;
	Q(int a=0,int b=0):u(a),v(b){}
	bool operator<(const Q &o) const {return v<o.v;}
};
char s[41];
int n,A,B,i,j,k,l,ans,T;
ll f[40][40][40][40];
ll la;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	T=1;
	cin>>T;
	while (T--)
	{
		cin>>n>>A>>B>>s;
		for (i=0;i<n;i++) s[i]-='0';
		memset(f,-1,sizeof f);
		f[0][s[0]%A][0][1]=1;f[0][0][s[0]%B][0]=0;
		for (i=0;i<n-1;i++) for (j=0;j<A;j++) for (k=0;k<B;k++) for (l=0;l<=i+1;l++) if (~f[i][j][k][l])
		{
			f[i+1][(j*10+s[i+1])%A][k][l+1]=f[i][j][k][l]<<1|1;
			f[i+1][j][(k*10+s[i+1])%B][l]=f[i][j][k][l]<<1;
			//cout<<i<<' '<<j<<' '<<k<<' '<<l<<' '<<f[i][j][k][l]<<endl;
		}
		ans=inf;
		for (i=1;i<n;i++) if ((~f[n-1][0][0][i])&&ans>abs(2*i-n))
		{
			ans=abs(2*i-n);
			la=f[n-1][0][0][i];
		}
		if (ans==inf) {cout<<"-1\n";continue;}
		for (i=0;i<n;i++) cout<<"BR"[la>>n-i-1&1];cout<<'\n';
	}
}