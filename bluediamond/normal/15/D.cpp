#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
const ll N=1000+7;
ll n,m,a,b;
ll s[N][N];
int v[N][N];
ll lg[N];

ll gets(ll r1,ll c1,ll r2,ll c2)
{
        return s[r2][c2]-s[r2][c1-1]-s[r1-1][c2]+s[r1-1][c1-1];
}

int aib[N][N];

void add(int i,int j)
{
        for(int x=i;x<=n;x+=x&(-x))
                for(int y=j;y<=m;y+=y&(-y))
                        aib[x][y]++;
}

int p(int i,int j)
{
        int s=0;
        for(int x=i;x>0;x-=x&(-x))
                for(int y=j;y>0;y-=y&(-y))
                        s+=aib[x][y];
        return s;
}

int func(int r1,int c1,int r2,int c2)
{
        return p(r2,c2)-p(r2,c1-1)-p(r1-1,c2)+p(r1-1,c1-1);
}

ll sol[N][N];
set <ll> active[N];

struct T
{
        ll sol;
        ll r;
        ll c;
};

bool operator < (T a,T b)
{
        if(a.sol!=b.sol)
                return a.sol<b.sol;
        if(a.r!=b.r)
                return a.r<b.r;
        return a.c<b.c;
}

struct triple
{
        int a;
        int b;
        ll c;
};
int v2[N][N];

bool block[N][N];

int dq[N],st,dr;

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        ///freopen("input","r",stdin);

        cin>>n>>m>>a>>b;

        for(ll i=1;i<=n;i++)
        {
                ll cur=0;
                for(ll j=1;j<=m;j++)
                {
                        cin>>v[i][j];
                        cur+=v[i][j];
                        s[i][j]=s[i-1][j]+cur;
                }
        }
        for(ll i=2;i<N;i++)
                lg[i]=1+lg[i/2];

        for(int i=1;i<=n;i++)
        {
                st=1;
                dr=0;
                for(int j=1;j<=m;j++)
                {
                        while(st<=dr && v[i][j]<=v[i][dq[dr]])
                                dr--;
                        dq[++dr]=j;
                        if(st<=dr && j-dq[st]+1>b)
                                st++;
                        if(j>=b)
                                v2[i][j-b+1]=v[i][dq[st]];
                }
        }

        for(int j=1;j<=m;j++)
        {
                st=1;
                dr=0;
                for(int i=1;i<=n;i++)
                {
                        while(st<=dr && v2[i][j]<=v2[dq[dr]][j])
                                dr--;
                        dq[++dr]=i;
                        if(st<=dr && i-dq[st]+1>a)
                                st++;
                        if(i>=a)
                                v[i-a+1][j]=v2[dq[st]][j];
                }
        }

        for(ll i=1;i+a-1<=n;i++)
                for(ll j=1;j+b-1<=m;j++)
                        sol[i][j]=gets(i,j,i+a-1,j+b-1)-(ll)a*(ll)b*(ll)v[i][j];
        for(ll i=1;i+a-1<=n;i++)
                for(ll j=1;j+b-1<=m;j++)
                        active[i].insert(j);

        vector <T> s;
        for(ll i=1;i+a-1<=n;i++)
                for(ll j=1;j+b-1<=m;j++)
                        s.push_back({sol[i][j],i,j});

        sort(s.begin(),s.end());

        vector <triple> ans;

        for(auto &it : s)
        {
                int r=it.r;
                int c=it.c;
                if(func(r,c,r+a-1,c+b-1)==0 && block[r][c]==0)
                {
                        ans.push_back({r,c,sol[r][c]});
                        for(int i=r;i<=r+a-1;i++)
                                for(int j=c;j<=c+b-1;j++)
                                        add(i,j);
                }
        }

        cout<<ans.size()<<"\n";
        for(auto &it : ans)
                cout<<it.a<<" "<<it.b<<" "<<it.c<<"\n";

        return 0;
}