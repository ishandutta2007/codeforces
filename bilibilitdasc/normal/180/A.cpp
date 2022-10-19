#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define per1(i,n) for(int i=(n);i>=1;i--)
#define repk(i,a,b) for(int i=(a);i<=(b);i++)
#define perk(i,a,b) for(int i=(a);i>=(b);i--)
#define rep0(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define g(x) cout<<#x<<'='<<x<<endl
#define nextp next_permutation
#define pq priority_queue
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
const int N=205;
vector<pair<int,int> > opr;
int a[N];
bool hv[N];
int n,m,nw;
bool chk()
{
	for(int i=1;i<=nw;i++) if(i!=a[i]) return 0; return 1;
}
int any()
{
	for(int i=1;i<=nw;i++) if(!hv[i]) return i; return 0;
}
void create(int _,int __)
{
	opr.pb(mp(_,__));
	hv[_]=0;
	hv[__]=1;
	a[__]=a[_];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int l;
		scanf("%d",&l);
		for(int j=0;j<l;j++)
		{
			int k;
			scanf("%d",&k);
			hv[k]=1;
			a[k]=++nw;
		}
	}
	while(!chk())
	{
		int k=any();
		if(k)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==k)
				{
					create(i,k);
					break;
				}
			}
		}
		else
		{
			int b,e;
			for(int i=0;i<=nw;i++) if(a[i]!=i) {b=i;break;}
			for(int i=nw+1;i<=n;i++) if(!hv[i]) {e=i;break;}
			create(b,e);
		}
	}
	cout<<opr.size()<<endl;
	for(int i=0;i<opr.size();i++)
	{
		cout<<opr[i].first<<' '<<opr[i].second;
		cout<<endl;
	}
	return 0;
}