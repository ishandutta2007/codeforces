#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 doijwfojeoif

using namespace std;

int n;

int in(int x, int y)
{
    while(x!=0 && y!=0)
    {
        int c=x%10;
        while(y!=0 && y%10!=c)
            y/=10;

        if(y%10==c)
            x/=10;
        y/=10;
    }

    if(x==0)
        return 1;
    else return 0;
}

int l(int x)
{
    int k=0;
    while(x)
    {
        x/=10;
        k++;
    }
    return k;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int Min=1e9;

    cin >> n;
    for(int i=1;i<50000;i++)
        if(in(i*i, n))
            Min=min(Min, l(n)-l(i*i));
    if(Min!=1e9)
        cout << Min;
    else cout << -1;
}