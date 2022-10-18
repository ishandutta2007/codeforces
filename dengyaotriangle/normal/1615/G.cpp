#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=300005;

namespace matching{//from uoj
const int M=maxn*2;
const int N=606;

int Head[M], Next[M], Go[M], Pre[N], Nxt[N], F[N], S[N], Q[N], Vis[N], *Top = Q, Cnt = 0, Tim = 0, n, m, x, y;

inline void addedge(int x, int y)
{
	Go[++Cnt] = y;
	Next[Cnt] = Head[x];
	Head[x] = Cnt;
}

int find(int x)
{
	return x == F[x] ? x : F[x] = find(F[x]);
}

int lca(int x, int y)
{
	for(Tim++, x = find(x), y = find(y); ; x ^= y ^= x ^= y)
		if(x)
		{
			if(Vis[x] == Tim) return x;
			Vis[x] = Tim;
			x = find(Pre[Nxt[x]]);
		}
}

void blossom(int x, int y, int l)
{
	while(find(x) != l)
	{
		Pre[x] = y, y = Nxt[x];
		if(S[y] == 1) S[*Top = y] = 0, *Top++;
		if(F[x] == x) F[x] = l;
		if(F[y] == y) F[y] = l;
		x = Pre[y];
	}
}

int Match(int x)
{
	for(int i = 1; i <= n; i++) F[i] = i;
	memset(S, -1, sizeof (int) * (n + 5));
	S[*(Top = Q) = x] = 0, Top++;
	for(int *i = Q; i != Top; *i++)
		for(int T = Head[*i]; T; T = Next[T])
		{
			int g = Go[T];
			if(S[g] == -1)
			{
				Pre[g] = *i, S[g] = 1;
				if(!Nxt[g])
				{
					for(int u = g, v = *i, lst; v; u = lst, v = Pre[u])
						lst = Nxt[v], Nxt[v] = u, Nxt[u] = v;
					return 1;
				}
				S[*Top = Nxt[g]] = 0, *Top++;
			}
			else if(!S[g] && find(g) != find(*i))
			{
				int l = lca(g, *i);
				blossom(g, *i, l);
				blossom(*i, g, l);
			}
		}
	return 0;
}
/*
	Read(n), Read(m);
	for(int i = 1; i <= m; i++)
	{
		Read(x), Read(y);
		addedge(x, y);
		addedge(y, x);
	}
	int ans = 0;
	for(int i = n; i >= 1; i--)
		if(!Nxt[i]) ans += Match(i);
	printf("%d\n", ans);
	for(int i = 1; i <= n; i++) printf("%d ", Nxt[i]);
	putchar('\n');
*/

}

int n,m;
int a[maxn];
pair<int,int> v[maxn];
vector<pair<int,int> > adj[maxn];
int typ[maxn];
int ans[maxn];
int t;

bool vis[maxn];
bool hvis[maxn];
int rt[maxn],cr;
int es,eu,ev;
int fa[maxn],fe[maxn];
void dfs(int u,int fae){
    rt[u]=cr;
    vis[u]=1;
    for(auto v:adj[u]){
        int ve,vw;tie(ve,vw)=v;
        if(vw!=fae){
            if(vis[ve]){
                if(es==-1)es=vw,eu=u,ev=ve;
            }else{
                fa[ve]=u;fe[ve]=vw;
                dfs(ve,vw);
            }
        }
    }
}
void orient(int i,int val){
    int l,r;tie(l,r)=v[i];
    if(a[l-1]==val)ans[l]=val,typ[i]=2;
    else ans[r]=val,typ[i]=3;
}
void dfs2(int u){
    hvis[u]=1;
    for(auto v:adj[u]){
        int ve,vw;tie(ve,vw)=v;
        if(!hvis[ve]){
            orient(vw,ve);
            dfs2(ve);
        }
    }
}


bool visg[maxn];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],visg[a[i]]=1;
    vector<int> col;
    for(int i=1;i<=n;i++)if(!visg[i])col.push_back(i);
    for(int i=1;i<=n;i++)ans[i]=a[i];
    m=max(1,*max_element(a+1,a+1+n));
    for(int i=1;i<n;i++)if(a[i]&&a[i]==a[i+1])vis[a[i]]=1;
    int l=-1;
    vector<tuple<int,int,int> > e2;
    for(int i=1;i<=n;i++){
        if(a[i]==0){
            if(l==-1)l=i;
            if(i==n||a[i+1]!=0){
                int r=i;
                int lv=0,rv=0;
                ++t;
                v[t]={l,r};
                if(l!=1&&!vis[a[l-1]])lv=a[l-1];
                if(r!=n&&!vis[a[r+1]])rv=a[r+1];
                if((r-l)&1){
                    if(lv&&rv&&lv!=rv){
                        e2.emplace_back(t,lv,rv);
                    }else{
                        typ[t]=1;
                    }
                }else{
                    if(lv&&rv){
                        adj[lv].emplace_back(rv,t);
                        adj[rv].emplace_back(lv,t);
                    }else if(lv){
                        adj[lv].emplace_back(lv,t);
                        adj[lv].emplace_back(lv,t);
                    }else if(rv){
                        adj[rv].emplace_back(rv,t);
                        adj[rv].emplace_back(rv,t);
                    }else{
                        typ[t]=1;
                    }
                }
                l=-1;
            }
        }
    }
    for(int i=1;i<=m;i++)if(!vis[i]){
        cr=i;
        es=-1;
        dfs(i,-1);
        if(es!=-1){
            orient(es,eu);
            for(int i=eu;i!=ev;i=fa[i]){
                hvis[i]=1;
                orient(fe[i],fa[i]);
            }
            hvis[ev]=1;
            for(int i=eu;;i=fa[i]){
                dfs2(i);
                if(i==ev)break;
            }
        }
    }
    map<pair<int,int>,int>rmp;
    for(auto&z:e2){
        int l,r,x;tie(x,l,r)=z;
        matching::n=m;
        if(!hvis[l]&&!hvis[r]){
            matching::addedge(rt[l],rt[r]);
            matching::addedge(rt[r],rt[l]);
            rmp[{rt[l],rt[r]}]=x;
            rmp[{rt[r],rt[l]}]=x;
        }
    }
    for(int i = matching::n; i >= 1; i--)if(!matching::Nxt[i]) matching::Match(i);
    for(int i=1;i<=m;i++){
        if(matching::Nxt[i]>i){
            int x1=matching::Nxt[i],x2=i;
            int x=rmp[{x1,x2}];
            int l,r;tie(l,r)=v[x];
            ans[l]=a[l-1];ans[r]=a[r+1];
            typ[x]=4;
            hvis[ans[l]]=1;
            dfs2(ans[l]);
            hvis[ans[r]]=1;
            dfs2(ans[r]);
        }
    }
    for(int i=1;i<=n;i++){
        if(!hvis[i])dfs2(i);
    }
    for(int i=1;i<=t;i++)if(typ[i]==0)typ[i]=1;
    for(int i=1;i<=t;i++){
        int l,r;tie(l,r)=v[i];
        int dl=typ[i];if(typ[i]>=3)dl-=2;
        for(int j=l+dl-1;j<=r;j+=2){
            if(typ[i]>=3&&j+1>r)break;
            ans[j]=col.back();col.pop_back();
            if(j+1<=r)ans[j+1]=ans[j];
        }
    }/*
    set<int> st;
    for(int i=1;i<n;i++)if(ans[i]==ans[i+1])st.insert(ans[i]);
    cout<<st.size();
    */
    for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
    return 0;
}