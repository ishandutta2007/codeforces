#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ull;

ull sum_dig(ull x)
{
    ull res=0;
    while(x)
    {
        res+=(x%10);
        x/=10;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ull n,s;
    cin >> n >> s;
    if(n<=s)
    {
        db(0)
    }
    else
    {
        ull res=0,i=s;
        for(;i<=n && i-s<200;i++)
        {
            if(abs(i-sum_dig(i))>=s)
                res++;
        }
        res+=n-i+1;
        db(res)
    }


    return 0;
}