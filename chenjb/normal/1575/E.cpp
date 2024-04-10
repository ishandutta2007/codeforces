#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define size sizz
using namespace std;
#define N 410000
#define inf 1000000007
#define int long long
int tree[2][N];
long long ans=0;
vector<int> del;
void update(long long &x,long long y)
{
    (x+=y)%=inf;
}
int lowbit(int x)
{
    return x & (-x);
}
void insert(int typ,int x)
{
    x++;
    if (x<=0)return;
    while (x<N)
    {
        del.pb(x);
        tree[typ][x]++;
        x+=lowbit(x);
    }
}
long long get(int typ,int x)
{
    x++;
    if (x<=0)return 0;
    long long ret=0;
    while (x)
    {
        update(ret,tree[typ][x]);
        x-=lowbit(x);
    }
    return ret;
}

struct EDGE
{
    int adj,next,w,valid;
}edge[2*N];
int gh[N],n,k,w[N],top,maxdist,size[N],son[N];
void addedge(int x, int y, int w) {
	edge[++top].adj = y;
	edge[top].valid = 1;
    edge[top].w=w;
	edge[top].next = gh[x];
	gh[x] = top;
}
void get_size(int x, int root=0) {
	size[x] = 1; son[x] = 0;
	int dd = 0;
	for (int p=gh[x]; p; p=edge[p].next)
		if (edge[p].adj != root && edge[p].valid) {
			get_size(edge[p].adj, x);
			size[x] += size[edge[p].adj];
			if (size[edge[p].adj] > dd) {
				dd = size[edge[p].adj];
				son[x] = edge[p].adj;
			}
		}
}
int getroot(int x) {
	get_size(x);
	int sz = size[x];
	while (size[son[x]] > sz/2)
		x = son[x];
	return x;
}
vector<pair<long long,int> > q[N][2];
void dfs(int x,int pre,int prec,long long sum,int cnt,int typ,int root)
{
    if (cnt>k)return;
    update(sum,w[x]);
    q[root][typ].pb(mp(sum,cnt));
    for(int p=gh[x];p;p=edge[p].next)
    {
        if (edge[p].valid==0)continue;
        if (edge[p].adj==pre)continue;
        dfs(edge[p].adj,x,edge[p].w,sum,cnt+(edge[p].w!=prec),typ,root);
    }
}
void dc(int x) {
	x = getroot(x);
	static int list[N], ltop;
	ltop = 0;
	for (int p=gh[x]; p; p=edge[p].next)
		if (edge[p].valid)
			list[++ltop] = edge[p].adj;
    for(int p=gh[x];p;p=edge[p].next)
    {
        if (edge[p].valid==0)continue;
        q[edge[p].adj][0].clear(); 
        q[edge[p].adj][1].clear(); 
        dfs(edge[p].adj,x,edge[p].w,0,0,edge[p].w,edge[p].adj);
        for(auto t:q[edge[p].adj][0])update(ans,t.first+w[x]);
        for(auto t:q[edge[p].adj][1])update(ans,t.first+w[x]);
    }
    update(ans,w[x]);
    /*
    cout<<x<<":"<<endl;
    for(int i=1;i<=ltop;i++)
    {
        cout<<"son "<<list[i]<<endl;
        cout<<"q[0]"<<":"<<endl;
        for(auto p:q[list[i]][0])cout<<p.first<<" "<<p.second<<endl;
        
        cout<<"q[1]"<<":"<<endl;
        for(auto p:q[list[i]][1])cout<<p.first<<" "<<p.second<<endl;
    } 
    */
    //cout<<ans<<endl;
    for(int t=0;t<=1;t++)
    {
        if (t==1)
            reverse(list+1,list+ltop+1);
        del.clear();
        for(int i=1;i<=ltop;i++)
        {
            long long delta=0;
            if (t==0)delta=w[x];
            for(auto p:q[list[i]][0])
                update(ans,(p.first+delta)*(get(0,k-p.second)+get(1,k-p.second-1))%inf);
            for(auto p:q[list[i]][1])
                update(ans,(p.first+delta)*(get(1,k-p.second)+get(0,k-p.second-1))%inf);    
            //cout<<list[i]<<" "<<ans<<endl;
            for(auto p:q[list[i]][0])insert(0,p.second);
            for(auto p:q[list[i]][1])insert(1,p.second);
        }
        for(auto p:del)tree[0][p]=tree[1][p]=0;
        //cout<<ans<<endl;
    }

    
	//be careful about the root
	for (int p=gh[x]; p; p=edge[p].next)
		if (edge[p].valid) {
			edge[p].valid = 0;
			edge[p^1].valid = 0;
			dc(edge[p].adj);
        }
       
}
signed main()
{
    //freopen("1.in","r",stdin);
    cin>>n>>k;
    for(int i=1;i<=n;i++)scanf("%lld",&w[i]);
    top=1;
    for(int i=1;i<n;i++)
    {
        int x,y,w; scanf("%lld%lld%lld",&x,&y,&w);
        addedge(x,y,w);
        addedge(y,x,w);
    }   
    dc(1);
    cout<<ans<<endl;
    return 0;
}