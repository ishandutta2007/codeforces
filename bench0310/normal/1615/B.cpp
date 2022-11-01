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
        auto f=[&](int n,int b)->int
        {
            n++;
            int p=(1<<(b+1));
            int c=(n/p);
            int r=(n%p);
            return (c*(p/2)+max(0,r-p/2));
        };
        auto g=[&](int l,int r,int b)->int{return f(r,b)-f(l-1,b);};
        int l,r;
        cin >> l >> r;
        int res=r-l+1;
        for(int b=0;b<29;b++) res=min(res,r-l+1-g(l,r,b));
        cout << res << "\n";
    }
    return 0;
}