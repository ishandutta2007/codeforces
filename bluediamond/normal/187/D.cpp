#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
const int N=(int) 1e5+7;
const int INF=(int) 1e9;
int n;
int g;
int r;
int cy;
int len[N];
int pre[N];
int val[N];
int zob[N];

/// dist(i, j) = pre[j]-pre[i]

int rep(int x)
{
        x%=cy;
        if (x<0)
                x+=cy;
        return x;
}

struct T
{
        int pos;
        int m1;
        int m2;
        int i;
};

bool operator < (T a,T b)
{
        return a.m2<b.m2;
}

int tree[4*N];

void upd(int v,int tl,int tr,int i,int x)
{
        if (tr<i||i<tl)
                return;
        if (tl==tr)
                tree[v]=x;
        else
        {
                int tm=(tl+tr)/2;
                upd(2*v,tl,tm,i,x);
                upd(2*v+1,tm+1,tr,i,x);
                tree[v]=max(tree[2*v],tree[2*v+1]);
        }
}

void upd(int i,int x)
{
        upd(1,1,n,i,x);
}

vector<T> v;
int sol[2*N];
int id;

void ask(int pos,int m1,int m2)
{
        id++;
        sol[id]=-1;
        m1=rep(m1);
        m2=rep(m2);
        if (m1<=m2)
        {
                v.push_back({pos,m1,m2,id});
        }
        else
        {
                v.push_back({pos,0,m2,id});
                v.push_back({pos,m1,cy-1,id});
        }
}


void calc_zob(int i,int tp)
{
        if (tp==1)
                ask(i+1,g+pre[i],cy-1+pre[i]);
        else
        {
                id++;
                int j=sol[id];
                if (j==-1)
                        zob[i]=pre[n+1]-pre[i];
                else
                        zob[i]=pre[j]-pre[i]+cy-(pre[j]-pre[i])%cy+zob[j];
        }
}

int query(int t,int tp)
{
        if (tp==1)
                ask(1,g-t,cy-1-t);
        else
        {
                id++;
                int j=sol[id];
                if (j==-1)
                        return t+pre[n+1];
                else
                        return t+pre[j]+cy-(t+pre[j])%cy+zob[j];
        }
        return 0;
}

int o[N];

int first(int v,int tl,int tr,int i,int val)
{
        if (tr<i)
                return 0;
        if (i<=tl)
        {
                if (tree[v]<val)
                        return 0;
                if (tl==tr)
                        return tl;
        }
        int tm=(tl+tr)/2;
        int j=first(2*v,tl,tm,i,val);
        if (!j)
                j=first(2*v+1,tm+1,tr,i,val);
        return j;
}

int first(int i,int val)
{
        return first(1,1,n,i,val);
}

signed main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin>>n>>g>>r;
        cy=g+r;
        for (int i=1;i<=n+1;i++)
                cin>>len[i];
        for (int i=1;i<=n+1;i++)
        {
                pre[i]=pre[i-1]+len[i];
                val[i]=pre[i]%cy;
        }
        for (int i=n;i>=1;i--)
        {
                calc_zob(i,1);
        }
        int q;
        cin>>q;
        for (int i=1;i<=q;i++)
        {
                cin>>o[i];
                query(o[i],1);
        }
        sort(v.begin(),v.end());
        vector<pair<int,int>> pr;
        for (int i=1;i<=n;i++)
                pr.push_back({val[i],i});
        sort(pr.begin(),pr.end());
        for (int i=1;i<=n;i++)
                upd(i,-INF);
        int i=0;
        for (auto &it : v)
        {
                while (i<(int) pr.size() && pr[i].first<=it.m2)
                {
                        upd(pr[i].second,val[pr[i].second]);
                        i++;
                }
                int kek=first(it.pos,it.m1);
                if (kek==0)
                        continue;
                if (sol[it.i]==-1)
                        sol[it.i]=kek;
                else
                        sol[it.i]=min(sol[it.i],kek);
        }
        id=0;
        for (int i=n;i>=1;i--)
        {
                calc_zob(i,2);
        }
        for (int i=1;i<=q;i++)
        {
                cout<<query(o[i],2)<<"\n";
        }
}