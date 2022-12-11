#include<cstdio>
#include<algorithm>
#include<cctype>
#include<vector>
#include<iostream>
#define pb push_back
#define forall(x,i) for (int i=0,_t=x.size();i<_t;i++)
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
typedef long long ll;

int m,n;
int a[100010],b[100010];
vector<int> d[100010];  //set i
vector<int> e[100010];  //set containing i
bool cmp1(int x,int y){return b[x]<b[y]||b[x]==b[y]&&x<y;}
bool cmp2(int x,int y){return a[x]<a[y]||a[x]==a[y]&&x<y;}
int f[100010];
int find(int x){return f[x]?f[x]=find(f[x]):x;}
struct Rec{
	int x,y;
}rec[200010]; int top;
bool operator<(Rec x,Rec y){
	return a[x.x]+b[x.y]>a[y.x]+b[y.y];
}
int main()
{
	m=read(),n=read();
	for (int i=1;i<=m;i++) a[i]=read();
	for (int i=1;i<=n;i++) b[i]=read();
	for (int i=1;i<=m;i++){
		int t=read();
		while (t--){
			int x=read();
			d[i].pb(x);
			e[x].pb(i);
			rec[++top]=(Rec){i,x};
		}
	}
	for (int i=1;i<=m;i++) sort(d[i].begin(),d[i].end(),cmp1);
	for (int i=1;i<=n;i++) sort(e[i].begin(),e[i].end(),cmp2);
	ll ans=0;
	sort(rec+1,rec+top+1);
	for (int i=1;i<=top;i++){
		int x=rec[i].x,y=rec[i].y;
//		printf("work %d %d\n",x,y);
		int t=lower_bound(e[y].begin(),e[y].end(),x,cmp2)-e[y].begin();
//		forall(e[y],j) printf("e %d find %d\n",y,e[y][j]);
//		printf("test %d %d\n",e[y].size(),t);
		if (t+1==e[y].size()) continue;
		int u=find(e[y][t]),v=find(e[y][t+1]);
		if (u^v) f[u]=v;
		else ans+=a[x]+b[y];
//		printf("work' %d %d\n",x,y);
	}
	cout<<ans<<endl;
	return 0;
}