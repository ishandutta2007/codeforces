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
    x*=f;return;
}
inline void print(int x,char ch) {
	if(x<0){ putchar('-');x=-x;}
	if(x>9) print(x/10,'\0');putchar(x%10+'0');
	if(ch!='\0') putchar(ch);return;
}
int n,m;
vector<int> v[maxn];
int s[maxn];
int mn[maxn];
int a[maxn];
int dfs(int cur)
{
	//cout<<a[cur]<<" "<<s[cur]<<" "<<k<<endl;
	for(int i=0;i<v[cur].size();i++)
	{
		int u=v[cur][i];
		int p=dfs(u);
		if(s[cur]==-1) 
		{
			if(mn[cur]==-1&&p>=0) mn[cur]=p;
			else mn[cur]=min(mn[cur],p);
		}
	}
	return mn[cur];
}
void dfs2(int cur,int k)
{
	if(mn[cur]==-1) mn[cur]=k;
	a[cur]=mn[cur]-k;
	for(int i=0;i<v[cur].size();i++)
		dfs2(v[cur][i],mn[cur]);
	return;
}
int main()
{
	int i,j;
	cin>>n;
	for(i=2;i<=n;i++)
	{
		int x;
		cin>>x;
		v[x].push_back(i);
	}
	for(i=1;i<=n;i++)
	{
		cin>>s[i];
		mn[i]=s[i];
	}
	//memset(mn,0x3f,sizeof(mn));
	#ifdef TIME
		clock_t ST=clock();
	#endif
	dfs(1);
	//for(i=1;i<=n;i++) cout<<mn[i]<<" ";
	//cout<<endl;
	dfs2(1,0);
	//for(i=1;i<=n;i++) cout<<mn[i]<<" ";
	ll ans=0;
	for(i=1;i<=n;i++)
	{
		ans+=a[i];
		if(a[i]<0)
		{
			cout<<-1;
			return 0;
		}
	}
	cout<<ans;
	#ifdef TIME
		printf("\n%.2lf ms",double(clock()-ST)/CLOCKS_PER_SEC*1000.0);
	#endif
	return 0;
}