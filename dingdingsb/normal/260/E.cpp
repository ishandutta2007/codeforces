#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=1e5+10;
int n,a[10];pair<int,int>p[N];
vector<int>X,Y;
int xpre[N];
int ypre[N];
bool vis[N];int mem[N];
struct qry{
	bool flag;
	int s1,s2;
	int h1,h2;
}q[400000];
struct qry2{
	int x,y;
	int need,id;
}q2[4000000];
int cnt1=0,cnt2=0;
void dfs(int now){
	if(now==9){
		int s1=lower_bound(xpre+1,xpre+X.size()+1,mem[1]+mem[4]+mem[7])-xpre;
		if(xpre[s1]!=mem[1]+mem[4]+mem[7])return;
		int s2=lower_bound(xpre+1,xpre+X.size()+1,n-mem[3]-mem[6]-mem[9])-xpre;
		if(xpre[s2]!=n-mem[3]-mem[6]-mem[9])return;
		int h1=lower_bound(ypre+1,ypre+Y.size()+1,mem[7]+mem[8]+mem[9])-ypre;
		if(ypre[h1]!=mem[7]+mem[8]+mem[9])return;
		int h2=lower_bound(ypre+1,ypre+Y.size()+1,n-mem[1]-mem[2]-mem[3])-ypre;
		if(ypre[h2]!=n-mem[1]-mem[2]-mem[3])return;
		q[++cnt1]={1,s1,s2,h1,h2};
		q2[++cnt2]={s1,h1,mem[7],cnt1};
		q2[++cnt2]={s2,h1,mem[7]+mem[8],cnt1};
		//q2[++cnt2]={(int)X.size(),h1,mem[7]+mem[8]+mem[9],cnt1};
		
		q2[++cnt2]={s1,h2,mem[7]+mem[4],cnt1};
		q2[++cnt2]={s2,h2,mem[7]+mem[8]+mem[4]+mem[5],cnt1};
		q2[++cnt2]={(int)X.size(),h2,n-mem[1]-mem[2]-mem[3],cnt1};
		
		//q2[++cnt2]={s1,(int)Y.size(),mem[1]+mem[4]+mem[7],cnt1};
		//q2[++cnt2]={s2,(int)Y.size(),n-mem[3]-mem[6]-mem[9],cnt1};
		//q2[++cnt2]={(int)X.size(),(int)Y.size(),n,cnt1}; 
		return;
	}
	for(int i=1;i<=9;i++)
		if(!vis[i]){
			vis[i]=1;
			mem[now+1]=a[i];
			dfs(now+1);
			vis[i]=0;
		}
}
vector<int>Y_Value[N];
vector<int>Q_Index[N];
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&p[i].first,&p[i].second),
		X.pb(p[i].first),Y.pb(p[i].second);
	sort(X.begin(),X.end());X.resize(unique(X.begin(),X.end())-X.begin());
	sort(Y.begin(),Y.end());Y.resize(unique(Y.begin(),Y.end())-Y.begin());
	for(int i=1;i<=n;i++)
		p[i].first=lower_bound(X.begin(),X.end(),p[i].first)-X.begin()+1,
		p[i].second=lower_bound(Y.begin(),Y.end(),p[i].second)-Y.begin()+1,
		Y_Value[p[i].first].pb(p[i].second);
	for(int i=1;i<=n;i++)
		xpre[p[i].first]++,
		ypre[p[i].second]++;
	for(int i=1;i<=n;i++)
		xpre[i]+=xpre[i-1],ypre[i]+=ypre[i-1];
	for(int i=1;i<=9;i++)
		scanf("%d",&a[i]);
	dfs(0);
	static int tree[N];memset(tree,0,sizeof tree);
	#define lowbit(x) ((x)&-(x))
	auto upd=[&](int x,int val){
		for(;x<=n;x+=lowbit(x))
			tree[x]+=val;
	};
	auto qry=[&](int x){
		int sum=0;
		for(;x;x-=lowbit(x))
			sum+=tree[x];
		return sum;
	};
	for(int i=1;i<=cnt2;i++)
		Q_Index[q2[i].x].pb(i);
	for(int i=1;i<=(int)X.size();i++){
		for(auto j:Y_Value[i])
			upd(j,1);
		for(auto j:Q_Index[i])
			q[q2[j].id].flag&=(qry(q2[j].y)==q2[j].need);
	}
	for(int i=1;i<=cnt1;i++)if(q[i].flag){
		printf("%.1lf %.1lf\n",1.0*(X[q[i].s1-1]+X[q[i].s1])/2,1.0*(X[q[i].s2-1]+X[q[i].s2])/2);
		printf("%.1lf %.1lf",1.0*(Y[q[i].h1-1]+Y[q[i].h1])/2,1.0*(Y[q[i].h2-1]+Y[q[i].h2])/2);
		return 0;
	}
	puts("-1");
}