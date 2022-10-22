#include <bits/stdc++.h>
#define int long long

using namespace std;

int q, n, L, R, M;
int f(int x)
{
    if(x==2)
        return n-1;
    return min(2*(n-x), n-x+x*(x-1)/2);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> q;
    while(q--)
    {
        cin >> n;
        L=1;
        R=n;
        while(R-L>1)
            {
                int M=(L+R)/2;
                if(f(M)>=f(M+1))
                    R=M;
                else L=M;
            }
        cout << f(R) << endl;
    }
    return 0;
}