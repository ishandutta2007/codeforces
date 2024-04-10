#include <bits/stdc++.h>

using namespace std;

const int N=5000+7;

int n;
int v[N];

bool prie(int x)
{
        if(x<=1)
        {
                return 0;
        }
        for(int i=2;i*i<=x;i++)
        {
                if(x%i==0)
                {
                        return 0;
                }
        }
        return 1;
}

int ans[N];

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        vector<int>p;
        for(int i=1;i<=(int)1e4+123;i++)
        {
                if(prie(i))
                {
                        p.push_back(i);
                }
        }
        cin>>n;
        for(int i=1;i<=n;i++)
        {
                int x;
                cin>>x;
                if(x==0) continue;
                int res=1;
                bool inv=0;
                if(x<0)
                {
                        inv=1;
                        x=-x;
                }
                for(auto &y:p)
                {
                        int cnt=0;
                        while(x%y==0)
                        {
                                x/=y;
                                cnt++;
                        }
                        if(cnt%2==1)
                        {
                                res*=y;
                        }
                }
                res*=x;
                if(inv)
                {
                        res=-res;
                }
                v[i]=res;
                continue;
                cout<<res<<" ";
        }
        unordered_map<int,int>f;
        for(int l=1;l<=n;l++)
        {
                int cnt=0;
                f.clear();
                for(int r=l;r<=n;r++)
                {
                        f[v[r]]++;
                        if(f[v[r]]==1 && v[r]!=0)
                        {
                                cnt++;
                        }
                        ans[max(cnt,1)]++;
                }
        }
        for(int i=1;i<=n;i++)
        {
                cout<<ans[i]<<" ";
        }
        cout<<"\n";
        return 0;
}