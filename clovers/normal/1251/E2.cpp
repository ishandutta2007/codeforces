#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=300001;
#define mk make_pair

struct node{
	ll val;
	int m,id;
	bool operator < (const node &rhs) const
	{
		if(val==rhs.val) return m<rhs.id;
		return val<rhs.val;
	}
}a[N];
set<node> st;
int t,n,bl[N];
vector<ll> v[N];
priority_queue<ll,vector<ll>,greater<ll> > q;

bool cmp(node x,node y)
{
	if(x.m==y.m) return x.val>y.val;
	return x.m<y.m;
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		ll ans=0;
		scanf("%d",&n);
		st.clear();
		for(int i=0;i<=n;i++) v[i].clear();
		for(int i=1;i<=n;i++) 
		{
			bl[i]=0;
			scanf("%d%lld",&a[i].m,&a[i].val);
			a[i].id=i;
			v[a[i].m].push_back(a[i].val);
		}
		while(!q.empty()) q.pop();
		for(int i=n-1;i>=0;i--)
		{
			sort(v[i].begin(),v[i].end());
			for(int j=0;j<(int)v[i].size();j++) q.push(v[i][j]);
			//cout<<i<<" "<<(int)q.size()<<endl;
			while((int)q.size()>n-i)
			{
				ll u=q.top();
				ans+=u;
				q.pop();
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}