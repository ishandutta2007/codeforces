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
		int n,i,j,ans,na;
		string s;
		cin>>n>>s;ans=n+1;
		for (char c='a';c<='z';c++)
		{
			na=0;
			i=0;j=n-1;
			while (i<j)
			{
				if (s[i]==s[j]) {++i;--j;continue;}
				if (s[i]!=s[j]&&s[i]!=c&&s[j]!=c) break;
				if (s[i]==c) ++i,++na; else --j,++na;
			}
			if (i<j) continue;
			ans=min(ans,na);
		}
		cout<<(ans==n+1?-1:ans)<<'\n';
	}
}