#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(int)3e5+7;

int n;
int t[N];
vector<int>g[N];

int leaf=0;

int dfs(int nod)
{
        if(g[nod].size()==0)
        {
                return 1;
        }
        if(t[nod]==0)
        {
                int res=0;
                for(auto &nou:g[nod])
                {
                        res+=dfs(nou);
                }
                return res;
        }
        else
        {
                int res=(1<<30);
                for(auto &nou:g[nod])
                {
                        res=min(res,dfs(nou));
                }
                return res;
        }

}


int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n;
        for(int i=1;i<=n;i++)
        {
                cin>>t[i];
        }
        for(int i=2;i<=n;i++)
        {
                int p;
                cin>>p;
                g[p].push_back(i);
        }
        for(int i=1;i<=n;i++)
        {
                leaf+=(g[i].size()==0);
        }
        cout<<leaf-dfs(1)+1<<"\n";
        return 0;
}
/**

**/