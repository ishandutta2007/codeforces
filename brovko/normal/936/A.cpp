#include <bits/stdc++.h>
#define int long long
#define y1 dwihweoighweoi
#define ld long double

using namespace std;
const ld eps=1e-10;

int k, d, t;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k >> d >> t;
    d*=(k+d-1)/d;
    ld L=0;
    ld R=2e18;
    for(int i=0;i<1000;i++)
    {
        ld M=(L+R)/2;

        ld r=M-d*(int)(M/d);
        ld x=(int)(M/d)*k+min(r, (ld)k);
        ld y=M-x;
        ld z=x/t+y/(2*t);

        if(z>=1)
            R=M;
        else L=M;
    }
    cout << setprecision(20) << L;
}