#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        int res=0;
        while(n%2==0 || n%3==0 || n%5==0)
        {
            if(!(n&1))
            {
                n/=2;
                res++;
            }
            if(n%3==0)
            {
                res++;
                n/=3;
                n*=2;
            }
            if(n%5==0)
            {
                res++;
                n/=5;
                n*=4;
            }
        }
        if(n==1)
            db(res)
        else
            db(-1)
    }
    return 0;
}