#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define ld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sqr(a) ((a)*(a))
#define bs ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define el "\n"
using namespace std;

void file()
{
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
}

int n,m,x,y,ans,g[101],kol;
bool f;
vector<int> a[101];
int main()
{
    //bs;
    //file();
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    for(int i=1;i<=n;++i)
    {
        f=false;
        kol=0;
        for(int j=1;j<=n;++j)
        {
            if(a[j].size()==1)
            {
                kol++;
                g[kol]=j;
                f=true;
            }
        }
        if(f)ans++;
        else break;
        for(int v=1;v<=kol;++v)
        {
            int j=g[v];
            //cout<<j<<el;
            for(int k=0;k<a[a[j][0]].size();++k)
                {
                    if(a[a[j][0]][k]==j)
                    {
                        a[a[j][0]].erase(a[a[j][0]].begin()+k);
                    }
                }
                if(a[j].size()!=0)
                a[j].erase(a[j].begin());
        }
    }
    cout<<ans;
}