#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=500000+7;
const int INF=(int) 1e9;
int n;
int a[N];
int z[N];
vector<int> pz;
bool vis[N];
int l[N];
int r[N];
bool taken[N];
vector<int> fi[N];
vector<int> sc[N];

int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);

        int t;
        cin>>t;
        while (t--)
        {
                pz.clear();
                cin>>n;
                for (int i=1;i<=n;i++)
                {
                        l[i]=r[i]=-1;
                        cin>>a[i];
                        z[i]=z[i-1]+(a[i]==0);
                        if (a[i]==0)
                                pz.push_back(i);
                }
                int lim=z[n]/2;
                if (lim==0)
                {
                        cout<<"0\n";
                        continue;
                }
                int pivot=0;
                while (pivot+1<=n&&z[pivot+1]<lim)
                        pivot++;
                /// 1...pivot => first group
                /// pivot+1...n => second group
                for (int i=1;i<=n;i++)
                        vis[i]=0;
                for (int i=pivot;i>=1;i--)
                        if (vis[a[i]]==0)
                        {
                                l[a[i]]=z[i];
                                vis[a[i]]=1;
                        }
                for (int i=1;i<=n;i++)
                        vis[i]=0;
                for (int i=pivot+1;i<=n;i++)
                        if (vis[a[i]]==0)
                        {
                                r[a[i]]=z[i]+1;
                                vis[a[i]]=1;
                        }
                for (int i=1;i<=n;i++)
                        vis[i]=0;
                /// 1...l[i] and r[i]...z[n]
                for (int i=1;i<=n;i++)
                {
                        if (l[i]==-1)
                                l[i]=0;
                        if (r[i]==-1)
                                r[i]=z[n]+1;
                        fi[i].clear();
                        sc[i].clear();
                }
                for (int i=1;i<=n;i++)
                        r[i]=z[n]-r[i]+1;
                for (int i=1;i<=n;i++)
                {
                        fi[l[i]].push_back(i);
                        sc[r[i]].push_back(i);
                }
                set<pair<int,int>> s1,s2;
                int sol=0;
                for (int t=z[n];t>=1;t--)
                {
                        for (auto &i:fi[t])
                                s1.insert(make_pair(r[i],i));
                        for (auto &i:sc[t])
                                s2.insert(make_pair(l[i],i));
                        while (!s1.empty())
                        {
                                auto it=*s1.begin();
                                s1.erase(it);
                                if (vis[it.second])
                                        continue;
                                vis[it.second]=1;
                                sol++;
                                break;
                        }
                        while (!s2.empty())
                        {
                                auto it=*s2.begin();
                                s2.erase(it);
                                if (vis[it.second])
                                        continue;
                                vis[it.second]=1;
                                sol++;
                                break;
                        }
                }
                cout<<min(lim,sol)<<"\n";
        }

}