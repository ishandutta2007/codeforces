#include <bits/stdc++.h>

using namespace std;

const int LIM=2000000+5;
const int N=1000+5;

int n;
int v[N];

int f[LIM];
int lp[LIM];
int p[LIM],cnt=0;

inline bool isp(int x)
{
    return (lp[x]==x);
}

vector<int>best(vector<int>a,vector<int>b)
{
    if(a.size()>b.size())
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main()
{
   /// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i=2;i<LIM;i++)
    {
        if(lp[i]==0)
        {
            lp[i]=i;
            p[++cnt]=i;
        }
        for(int j=1;j<=cnt && p[j]<=lp[i] && p[j]*i<LIM;j++)
        {
            lp[p[j]*i]=p[j];
        }
    }
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        f[v[i]]++;
    }
    vector<int>ans;
    vector<int>cur;
    cur.clear();
    cur.push_back(v[1]);
    ans=best(ans,cur);

    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(isp(v[i]+v[j]))
            {
                cur.clear();
                cur.push_back(v[i]);
                cur.push_back(v[j]);
                ans=best(ans,cur);
            }
        }
    }

    if(f[1])
    {
        cur.clear();
        for(int i=1;i<=f[1];i++)
        {
            cur.push_back(1);
        }
        for(int i=1;i<=n;i++)
        {
            if(v[i]!=1 && isp(v[i]+1))
            {
                cur.push_back(v[i]);
                break;
            }
        }
        ans=best(ans,cur);
    }

    cout<<ans.size()<<"\n";
    for(auto &x:ans)
    {
        cout<<x<<" ";
    }
    cout<<"\n";
    return 0;
}