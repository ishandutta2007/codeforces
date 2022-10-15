#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(int) 1e5+7;
int n;
int k;
int gold;
vector<int> g[N];
int dep[N];
int cnt[N];
ll s[N];
ll s2[N];
int dim;

void dfs(int a,int p)
{
        dim=max(dim,dep[a]);
        cnt[dep[a]]++;
        for (auto &b : g[a])
        {
                if (b==p)
                        continue;
                dep[b]=1+dep[a];
                dfs(b,a);
        }
}

ll eval(int l,int r)
{
        ll co=s2[r]-s2[l-1];
        ll sm=s[r]-s[l-1];
        return co+(ll)sm*r;
}

int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin>>n>>k>>gold;
        dep[1]=1;
        for (int i=1;i<n;i++)
        {
                int x,y;
                cin>>x>>y;
                g[x].push_back(y);
                g[y].push_back(x);
        }
        dfs(1,-1);
        cnt[1]=0;
        for (int i=1;i<=dim;i++)
        {
                s[i]=s[i-1]+cnt[i];
                s2[i]=s2[i-1]-(ll)i*cnt[i];
        }
        /// exchange arg => mereu iau pe toate de la ultimul nivel ca ma costa cel mai putin :))
        int sol=0,j=1;
        for (int i=1;i<=dim;i++)
        {
                while (eval(j,i)>gold)
                        j++;
                int gain=s[i]-s[j-1];
                ll rem=gold-eval(j,i);
                sol=max((ll)sol,gain+min((ll)cnt[j-1],rem/(i-j+1)));
        }
        sol=max(sol,1);
        sol=min(sol,k);
        cout<<sol<<"\n";
}