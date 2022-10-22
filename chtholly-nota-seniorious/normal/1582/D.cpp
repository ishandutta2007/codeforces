#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
#define all(x) (x).begin(),(x).end()
std::mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int sj(int n)
{
	ull x=rnd();
	x=x<<32|rnd();
	return x%n+1;
}
#define rand fst
const int p=998244353;
inline void inc(int &x,const int y){if((x+=y)>=p)x-=p;}
inline void dec(int &x,const int y){if((x-=y)<0)x+=p;}
inline int ksm(int x,int y)
{int r=1;while (y){if(y&1)r=(ll)r*x%p;x=(ll)x*x%p;y>>=1;}return r;}
priority_queue<int> ONLYYFORRCOPYY;
priority_queue<int,vector<int>,greater<int>> ONLYYFORRCOPYY__;
struct Q
{
	int u,v;
	Q(){}
	Q(int a,int b):u(a),v(b){}
	bool operator<(const Q &o) const {return v<o.v;}
};
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);

	int T;
	cin>>T;
	while (T--)
	{
		int n,i;
		cin>>n;
		vector<int> a(n);
		for (auto &x:a) cin>>x;
		if (1^n&1)
		{
			for (i=0;i<n;i+=2) cout<<a[i+1]<<' '<<-a[i]<<" \n"[i==n-2];
		}
		else
		{
			n-=3;
			for (i=0;i<n;i+=2) cout<<a[i+1]<<' '<<-a[i]<<' ';
			if (a[n]+a[n+1]==0&&a[n]+a[n+2]==0)
			{
				cout<<-(a[n+1]+a[n+2])<<' '<<a[n]<<' '<<a[n]<<'\n';
			}
			else if (a[n]+a[n+1]==0) cout<<a[n+1]<<' '<<-(a[n]+a[n+2])<<' '<<a[n+1]<<'\n';
			else 
			cout<<a[n+2]<<' '<<a[n+2]<<' '<<-(a[n]+a[n+1])<<'\n';
		}
	}
}