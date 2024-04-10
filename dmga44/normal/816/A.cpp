#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;

bool is_pal(int n,int m)
{
    if(n%10==m/10 && m%10==n/10)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int h,m;
    char c;
    cin >> h >> c >> m;
    int res=0;
    while(!(is_pal(h,m)))
    {
        if(m==59)
        {
            m=0;
            if(h==23)
            {
                h=0;
            }
            else
                h++;
        }
        else
        {
            m++;
        }
        res++;
    }
    db(res)
    return 0;
}