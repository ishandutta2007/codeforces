#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n+1,0);
        array<int,3> c={0,0,0};
        auto g=[&](int b)->int{return (b%3);};
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            c[g(a[i])]++;
        }
        ranges::sort(a);
        cout << [&]()->int
        {        
            if(g(a[n])==0) return (a[n]/3+(c[0]<n));
            else
            {
                if(a[n]==1) return 1;
                if(a[n]==2) return (1+(c[2]<n));
                //lower bound with [2,2]
                if(g(a[n])==1)
                {
                    vector<int> bad={1,a[n]-1};
                    bool ok=1;
                    for(int i=1;i<=n;i++) ok&=(a[i]!=1&&a[i]!=a[n]-1);
                    if(ok) return (a[n]/3+1);
                }
                return (a[n]/3+1+(c[3-g(a[n])]>0));
            }
        }() << "\n";
    }
    return 0;
}