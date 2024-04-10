#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int n;
        cin>>n;
        vector<int>v(n,0);
        for(int i=1;i<n;i++)
        {
                int dif;
                cin>>dif;
                v[i]=v[i-1]+dif;
        }
        int mi=0;
        for(auto &x:v)
        {
                mi=min(mi,x);
        }
        for(int i=0;i<n;i++)
        {
                v[i]=v[i]-mi;
        }
        vector<int>a=v;
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++)
        {
                if(a[i]!=i)
                {
                        cout<<"-1\n";
                        return 0;
                }
        }
        for(auto &x:v)
        {
                cout<<x+1<<" ";
        }
        cout<<"\n";
        return 0;
}
/**

**/