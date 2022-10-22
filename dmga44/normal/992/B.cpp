#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 32000

int gcd(int a,int b)
{
    if(!b)
        return a;
    return gcd(b,a%b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int l,r,a,b;
    cin >> l >> r >> a >> b;
    if(b%a!=0)
    {
        db(0)
        return 0;
    }
    int yy=b/a;
    int res=0;
    for(int i=1;i<=sqrt(yy);i++)
        if(yy%i==0)
        {
            int j=yy/i;
            int x1=i*a;
            int x2=j*a;
            if(gcd(i,j)==1 && l<=x1 && x1<=r && l<=x2 && x2<=r)
            {
                if(i==j)
                    res--;
                res+=2;
            }
        }

    db(res)
    return 0;
}