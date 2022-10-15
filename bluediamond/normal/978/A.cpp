#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int v[55];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    vector<int>a;
    for(int i=1;i<=n;i++)
    {
        bool ok=1;
        for(int j=i+1;j<=n;j++)
        {
            if(v[i]==v[j])
            {
                ok=0;
            }
        }
        if(ok) a.push_back(v[i]);
    }
    cout<<a.size()<<"\n";
    for(auto &x:a)
    {
        cout<<x<<" ";
    }
    return 0;
}