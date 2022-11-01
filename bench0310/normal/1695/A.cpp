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
        int n,m;
        cin >> n >> m;
        array<int,3> a={-(1<<30),0,0};
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int x;
                cin >> x;
                a=max(a,{x,i,j});
            }
        }
        auto f=[&](int l,int p)->int{return max(p,l-p+1);};
        cout << f(n,a[1])*f(m,a[2]) << "\n";
    }
    return 0;
}