#include <bits/stdc++.h>
#define int long long
using namespace std;

main()
{
    //freopen("input.txt", "r", stdin);
    int x, y, l, r, an=0;
    cin>>l>>r>>x>>y;
    if(y%x==0)
    {
        y/=x;
        for(int a=1; a*a<=y; a++)
        {
            if(y%a==0)
            {
                int ch1=a*x, ch2=(y/a)*x;
                if(ch1>=l and ch1<=r and ch2>=l and ch2<=r and __gcd(ch1, ch2)==x)
                {
                    an++;
                    if(ch1!=ch2) an++;
                }
            }
        }
    }
    cout<<an;
}