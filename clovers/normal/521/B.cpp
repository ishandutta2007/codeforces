#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100005;
typedef pair<int,int> pii;
#define mk make_pair
const int MOD=(int)1e9+9;
pii a[N];
int n;
map<pii,int> mp;
set<int> st;

void init()
{
    scanf("%lld",&n);
    st.clear();
    for(int i=0;i<n;i++)
    {
        scanf("%lld%lld",&a[i].first,&a[i].second);
        st.insert(i);
        mp[a[i]]=i+1;
    }
}
set<int> v[N],f[N];
int ans=0,vis[N];

int d[]={1,0,-1};
void solve()
{
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++) v[i].clear();
    for(int i=0;i<n;i++)
    {
        int x=a[i].first,y=a[i].second;
        if(y==0) continue;
        for(int t=0;t<3;t++)
        {
            int xx=x+d[t],yy=y-1;
            if(mp[mk(xx,yy)]) 
            {
                v[i].insert(mp[mk(xx,yy)]-1);
                f[mp[mk(xx,yy)]-1].insert(i);
            }
        }
        if((int)v[i].size()==1) st.erase(*v[i].begin());
    }
    int rnd=1,P=0;
    while(!st.empty())
    {
        P++;
        rnd^=1;
        set<int>::iterator it;
        int now;
        if(rnd==0) now=*st.rbegin();
        else now=*st.begin();
        vis[now]=1; ans=(ans*n%MOD+now)%MOD; st.erase(now);
        if(!f[now].empty()) for(it=f[now].begin();it!=f[now].end();it++)
        {
            int fa=*it;
            v[fa].erase(now);
            if(v[fa].size()==1) st.erase(*v[fa].begin());
        }
        if(!v[now].empty()) for(it=v[now].begin();it!=v[now].end();it++)
        {
            int son=*it;
            f[son].erase(now);
            if(f[son].empty()) st.insert(son);
            else
            {
                set<int>::iterator it2;
                int bl=1;
                for(it2=f[son].begin();it2!=f[son].end();it2++)
                {
                    int fa=*it2;
                    if(v[fa].size()==1) bl=0;
                }
                if(bl) st.insert(son);
            }
            
        }
    }
}

signed main()
{
    init();
    solve();
    cout<<ans<<endl;
    return 0;
}