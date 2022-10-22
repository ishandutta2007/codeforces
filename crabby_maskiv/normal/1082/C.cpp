#include<bits/stdc++.h>
//#define TIME
using namespace std;
typedef long long ll;
const int maxn=100005;
const int inf=0x3f3f3f3f;
inline void read(int &x) {
    int f=1;x=0;char c=getchar();
    while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    x*=f;
}
inline void print(int x) {
	if(x<0){ putchar('-');x=-x;}
	if(x>9) print(x/10);putchar(x%10+'0');
}
int n,m;
vector<ll> v[maxn];
set<int> s;
bool cmp(const ll &x,const ll &y)
{
	return x>y;
}
int main()
{
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++) 
	{
		ll r,s;
		cin>>r>>s;
		v[r].push_back(s);
	}
	
	#ifdef TIME
		clock_t ST=clock();
	#endif
	for(i=1;i<=m;i++) sort(v[i].begin(),v[i].end(),cmp);
	for(i=1;i<=m;i++)
		for(j=1;j<v[i].size();j++) 
			v[i][j]+=v[i][j-1];
	ll sum=0,mx=0;
	for(i=1;i<=m;i++)
		if(v[i].size()!=0) s.insert(i);
	set<int>::iterator it;
	for(i=0;i<n&&(!s.empty());i++)
	{
		sum=0;
		for(it=s.begin();it!=s.end();it++){
			if(v[*it][i]>0) sum+=v[*it][i];
		}
		for(it=s.begin();it!=s.end();)
		{
			if(i+1==v[*it].size()) 
				s.erase(it++);
			else it++;
		}
		mx=max(mx,sum);
	}
	cout<<mx;
	#ifdef TIME
		printf("\n%.2lf ms",double(clock()-ST)/CLOCKS_PER_SEC*1000.0);
	#endif
	return 0;
}