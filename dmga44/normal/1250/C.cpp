#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    swap(b,d);
    int x=min(c,d);
    if(x+a<=b)
        db(x*f+a*e)
    else
    {
        int res=0;
        if(e>f)
        {
            int m=min(a,b);
            res+=m*e;
            b-=m;
            a-=m;
        }
        else
        {
            int m=min(x,b);
            res+=m*f;
            b-=m;
            x-=m;
        }
        res+=(e*min(b,a)+f*min(b,x));
        db(res)
    }

    return 0;
}