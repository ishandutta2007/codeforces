#include <bits/stdc++.h>
#define int long long
#define y1 sdofhdodfhd

using namespace std;

int n, Max;
vector <int> v;

int gcd(int x, int y)
{
    if(x==0)
        return y;
    return gcd(y%x, x);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int L=0;
    int R=1e9;
    while(R-L>1)
    {
        int M=(L+R)/2;
        cout << "> " << M << endl;
        int x;
        cin >> x;
        if(x==1)
            L=M;
        else R=M;
    }
    int Max=R;

    mt19937 rnd(time(NULL));
    for(int i=0;i<30;i++)
    {
        cout << "? " << rnd()%n+1 << endl;
        int x;
        cin >> x;
        v.push_back(x);
    }

    int d=0;
    for(int i=0;i<30;i++)
        d=gcd(d, Max-v[i]);
    cout << "! " << Max-d*(n-1) << ' ' << d << endl;
}