#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    int sz=1;
    int t=1;
    while(t*k<=n-1)
    {
        sz++;
        t*=k;
    }
    auto f=[&](int a)->vector<int>
    {
        vector<int> v(sz,0);
        for(int i=sz-1;i>=0;i--)
        {
            v[i]=(a%k);
            a/=k;
        }
        return v;
    };
    cout << sz << "\n";
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            vector<int> a=f(i);
            vector<int> b=f(j);
            for(int x=0;x<sz;x++)
            {
                if(a[x]!=b[x])
                {
                    cout << x+1 << " ";
                    break;
                }
            }
        }
    }
    cout << "\n";
    return 0;
}