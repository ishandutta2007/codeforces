#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int n,r=0;
        cin>>n;
        vector<int>v(n);
        map<int,int>f;
        for(int i=0;i<n;i++)
        {
                cin>>v[i];
                f[v[i]]++;
        }
        for(auto &x:v)
        {
                int cur=0;
                for(int j=x;j<=x+5;j++)
                {
                        cur+=f[j];
                }
                r=max(r,cur);
        }
        cout<<r<<"\n";
        return 0;
}
/**

**/