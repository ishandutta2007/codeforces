#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(int)1e5+7;

int n;
int v[N];
vector <int> who[N];
bool active[N];

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n;
        for(int i=1;i<=n;i++)
        {
                cin>>v[i];
                who[v[i]].push_back(i);
        }
        ll cur=0LL,res=0LL;
        for(int x=n;x>=1;x--)
        {
                for(auto &j:who[x])
                {
                        active[j]=1;
                        if(active[j-1]==0 && active[j+1]==0)
                        {
                                cur+=(n+1-x);
                                continue;
                        }
                        if(active[j+1]==1 && active[j-1]==1)
                        {
                                cur+=(min(v[j-1],v[j+1])-x);
                                cur-=(n+1-max(v[j-1],v[j+1]));
                                continue;
                        }
                        int val;
                        if(active[j-1])
                        {
                                val=v[j-1];
                        }
                        else
                        {
                                val=v[j+1];
                        }
                        cur+=(val-v[j]);
                }
                res+=cur;
        }
        cout<<res<<"\n";
        return 0;
}