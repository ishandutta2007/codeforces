#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdifpghig

using namespace std;

int n, H;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> H;
    if(n<=H*(H+1)/2 || H>2e9)
    {
        int L=0;
        int R=2e9;
        while(R-L>1)
        {
            int M=(L+R)/2;
            if(M*(M+1)/2>=n)
                R=M;
            else L=M;
        }
        cout << R;
        return 0;
    }

    int L=H;
    int R=2e9;
    while(R-L>1)
    {
        int M=(L+R)/2;
        int x=M-(H+1);
        int s=H*(H+1)/2+H*(x+1);
        if(x%2==0)
            s+=x/2*(x/2+1);
        else s+=(x/2+1)*(x/2+1);
        if(s>=n)
            R=M;
        else L=M;
    }
    cout << R;
}