#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(int) 5e5+7;
const int K=730+7;
int n;
int q;
int k;
vector<vector<vector<int>>> days;

struct T
{
        int d;
        int x;
        int y;
};

T a[N];
int y;
int bucket[N];
int first[K];
int last[K];
int t[N];
int cnt[N];

void clr()
{
        for (int i=1;i<=n;i++)
                t[i]=i,
                cnt[i]=1;
}

int root(int x)
{
        if (t[x]==x)
                return x;
        else
                return t[x]=root(t[x]);
}

void unite(int x,int y)
{
        x=root(x);
        y=root(y);
        if (x!=y)
        {
                t[x]=y;
                cnt[y]+=cnt[x];
        }
}

int t2[N];
int cnt2[N];

int root2(int x)
{
        if (t2[x]==x)
                return x;
        else
                return t2[x]=root2(t2[x]);
}

void unite2(int x,int y)
{
        x=root(x);
        y=root(y);
        x=root2(x);
        y=root2(y);
        if (x!=y)
        {
                t2[x]=y;
                cnt2[y]+=cnt2[x];
        }
}

void tr(int x)
{
        x=root(x);
        t2[x]=x;
        cnt2[x]=cnt[x];
}


int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);


        cin>>n>>q>>k;
        days.push_back({});
        for (int i=1;i<=q;i++)
        {
                int tp;
                cin>>tp;
                if (tp==1)
                {
                        int x,y;
                        cin>>x>>y;
                        vector<int> v={x,y};
                        days.back().push_back(v);
                }
                if (tp==2)
                {
                        int x;
                        cin>>x;
                        vector<int> v={x};
                        days.back().push_back(v);
                }
                if (tp==3)
                {
                        days.push_back({});
                }
        }
        int d=0;
        for (auto &vec:days)
        {
                d++;
                for (auto &it:vec)
                        if ((int)it.size()==2)
                        {
                                a[++y]={d,it[0],it[1]};
                        }
        }
        int rad=sqrt(y);
        ///rad=1;
        for (int i=1;i<=y;i++)
                bucket[i]=(i-1)/rad+1;
        for (int i=1;i<=y;i++)
                last[bucket[i]]=i;
        for (int i=y;i>=1;i--)
                first[bucket[i]]=i;
        clr();
        int pos=0,l=1,r=0,nowd=0;
        for (auto &vec:days)
        {
                nowd++;
                int linit=l;
                while (l<=y&&a[l].d<=nowd-k)
                {
                        l++;
                }
                int aft=last[bucket[l]]+1;
                if (bucket[l]!=bucket[linit])
                {
                        clr();
                        for (int j=aft;j<=r;j++)
                                unite(a[j].x,a[j].y);
                }
                for (auto &it : vec)
                {
                        if ((int) it.size()==2)
                        {
                                r++;
                                if (r>=aft)
                                        unite(a[r].x,a[r].y);
                        }
                        else
                        {
                                if (l>r)
                                {
                                        cout<<"1\n";
                                        continue;
                                }
                                int x=it[0],to=min(r,aft-1);
                                tr(x);
                                for (int j=l;j<=to;j++)
                                        tr(a[j].x),tr(a[j].y);
                                for (int j=l;j<=to;j++)
                                        unite2(a[j].x,a[j].y);

                                cout<<cnt2[root2(root(x))]<<"\n";
                        }
                }
        }
}