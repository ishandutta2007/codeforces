#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto ok=[&](int n,int k)->bool
    {
        if((n%2)==0) return 0;
        if(k==0) return ((n&(n+1))==0);
        if(k==1) return ((n&(n+1))!=0);
        if(k==2) return (n>=7&&n!=9);
        return (k<=(n-3)/2);
    };
    vector<int> u;
    int id=0;
    function<void(int,int,int)> go=[&](int n,int k,int p)
    {
        int a=(++id);
        u[a]=p;
        if(n==1) return;
        if(n==11&&k==3)
        {
            go(3,0,a);
            go(7,2,a);
        }
        else if(n==17&&k==2)
        {
            go(3,0,a);
            go(13,1,a);
        }
        else if(k>=3||(k==2&&ok(n-2,k-1)))
        {
            go(n-2,k-1,a);
            go(1,0,a);
        }
        else if(k==0)
        {
            go((n-1)/2,0,a);
            go((n-1)/2,0,a);
        }
        else if(k==1)
        {
            for(int i=1;i<=n-2;i=2*i+1)
            {
                int x=(ok(n-1-i,1)+((2*i<=n-1-i)||(2*(n-1-i)<=i)));
                if(x==1)
                {
                    go(i,0,a);
                    go(n-1-i,ok(n-1-i,1),a);
                    break;
                }
            }
        }
        else if(k==2)
        {
            go((n-1)/2-3,1,a);
            go((n-1)/2+3,1,a);
        }
    };
    int n,k;
    cin >> n >> k;
    u.assign(n+1,0);
    if(ok(n,k))
    {
        go(n,k,0);
        cout << "YES\n";
        for(int i=1;i<=n;i++) cout << u[i] << " \n"[i==n];
    }
    else cout << "NO\n";
    return 0;
}