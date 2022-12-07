//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if(b==0) return a;
    else return gcd(b, a%b);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        int z=gcd(x, y);
        int x2=x/z, y2=y/z;
        if((1ll*z)%(1ll*x2*y2)==0)
        {
            z/=(x2*y2);
            int l=0, r=1e3+10;
            while(r-l>1)
            {
                int mid=(l+r)/2;
                if(mid*mid*mid<=z) l=mid;
                else r=mid;
            }
            if(l*l*l==z) cout<<"Yes\n";
            else cout<<"No\n";
        }
        else cout<<"No\n";
    }
}