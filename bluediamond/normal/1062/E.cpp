#include <bits/stdc++.h>

using namespace std;

const int N=100000+5;
const int LG=19;

int n,t;
vector<int>g[N];
int p[3*N],y=0;
int h[3*N];

int first[N];
int last[N];

int rmq[3*N][LG];
int who[3*N][LG];

int nownr=0;
int nr[N];

int lg[3*N];

inline void dfs(register int nod)
{
    nr[nod]=nownr++;
    if(g[nod].size()==0)
    {
        p[++y]=nod;
    }
    else
    {
        p[++y]=nod;
        for(auto &nou:g[nod])
        {
            h[nou]=h[nod]+1;
            dfs(nou);
            p[++y]=nod;
        }
    }
}

/// Arbori de intervale :


pair<int,int>arb_min[3*N];

inline void upd_min(int nod,int st,int dr,int poz,int val)
{
    if(dr<poz || poz<st)
    {
        return;
    }
    if(st==dr)
    {
        arb_min[nod]={val,poz};
        return;
    }
    int med=(st+dr)/2;
    upd_min(2*nod,st,med,poz,val);
    upd_min(2*nod+1,med+1,dr,poz,val);
    arb_min[nod]=min(arb_min[2*nod],arb_min[2*nod+1]);
}

inline pair<int,int>ask_min(int nod,int st,int dr,int x,int y)
{
    if(dr<x || y<st)
    {
        return {(1<<30),0};
    }
    if(x<=st && dr<=y)
    {
        return arb_min[nod];
    }
    int med=(st+dr)/2;
    return min(ask_min(2*nod,st,med,x,y),ask_min(2*nod+1,med+1,dr,x,y));
}


pair<int,int>arb_max[3*N];

inline void upd_max(int nod,int st,int dr,int poz,int val)
{
    if(dr<poz || poz<st)
    {
        return;
    }
    if(st==dr)
    {
        arb_max[nod]={val,poz};
        return;
    }
    int med=(st+dr)/2;
    upd_max(2*nod,st,med,poz,val);
    upd_max(2*nod+1,med+1,dr,poz,val);
    arb_max[nod]=max(arb_max[2*nod],arb_max[2*nod+1]);
}

inline pair<int,int>ask_max(int nod,int st,int dr,int x,int y)
{
    if(dr<x || y<st)
    {
        return {-(1<<30),0};
    }
    if(x<=st && dr<=y)
    {
        return arb_max[nod];
    }
    int med=(st+dr)/2;
    return max(ask_max(2*nod,st,med,x,y),ask_max(2*nod+1,med+1,dr,x,y));
}

inline pair<int,int> lca(int a,int b) /// level, who
{
    if(nr[a]>nr[b])
    {
        swap(a,b);
    }
    int st=first[a];
    int dr=last[b];
    int k=lg[dr-st+1];
    if(rmq[st][k]<rmq[dr-(1<<k)+1][k])
    {
        return {rmq[st][k],who[st][k]};
    }
    else
    {
        return {rmq[dr-(1<<k)+1][k],who[dr-(1<<k)+1][k]};
    }
}

pair<int,int>big_lca(int st,int dr) /// level, who
{
    pair<int,int>mi=ask_min(1,1,n,st,dr);
    pair<int,int>ma=ask_max(1,1,n,st,dr);
    return lca(mi.second,ma.second);
}

inline pair<int,int>NOmin(int st,int dr) /// returns level, nod
{
    pair<int,int>mi=ask_min(1,1,n,st,dr);
    upd_min(1,1,n,mi.second,(1<<30));
    upd_max(1,1,n,mi.second,-(1<<30));
    int lv=big_lca(st,dr).first;
    upd_min(1,1,n,mi.second,mi.first);
    upd_max(1,1,n,mi.second,mi.first);
    return {lv,mi.second};
}

inline pair<int,int>NOmax(int st,int dr) /// returns level, nod
{
    pair<int,int>ma=ask_max(1,1,n,st,dr);
    upd_min(1,1,n,ma.second,(1<<30));
    upd_max(1,1,n,ma.second,-(1<<30));
    int lv=big_lca(st,dr).first;
    upd_min(1,1,n,ma.second,ma.first);
    upd_max(1,1,n,ma.second,ma.first);
    return {lv,ma.second};
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(register int i=2;i<3*N;i++)
    {
        lg[i]=1+lg[i/2];
    }
    cin>>n>>t;
    register int dad;
    for(register int i=2;i<=n;i++)
    {
        cin>>dad;
        g[dad].push_back(i);
    }
    dfs(1);
    for(register int i=1;i<=y;i++)
    {
        last[p[i]]=i;
    }
    for(register int i=y;i>=1;i--)
    {
        first[p[i]]=i;
    }
    for(register int i=1;i<=y;i++)
    {
        rmq[i][0]=h[p[i]];
        who[i][0]=p[i];
    }
    for(register int k=1;(1<<k)<=y;k++)
    {
        for(register int i=1;i+(1<<k)-1<=y;i++)
        {
            if(rmq[i][k-1]<rmq[i+(1<<(k-1))][k-1])
            {
                rmq[i][k]=rmq[i][k-1];
                who[i][k]=who[i][k-1];
            }
            else
            {
                rmq[i][k]=rmq[i+(1<<(k-1))][k-1];
                who[i][k]=who[i+(1<<(k-1))][k-1];
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        upd_max(1,1,n,i,nr[i]);
        upd_min(1,1,n,i,nr[i]);
    }
    for(int tc=1;tc<=t;tc++)
    {
        int st,dr;
        cin>>st>>dr;
        pair<int,int>ans=max(NOmin(st,dr),NOmax(st,dr));
        cout<<ans.second<<" "<<ans.first<<"\n";
    }
    return 0;
}