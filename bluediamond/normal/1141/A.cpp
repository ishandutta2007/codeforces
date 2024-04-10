#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int a,b;
        cin>>a>>b;
        int a2=0,b2=0,a3=0,b3=0;
        while(a%2==0)
        {
                a2++;
                a/=2;
        }
        while(a%3==0)
        {
                a3++;
                a/=3;
        }
        while(b%2==0)
        {
                b/=2;
                b2++;
        }
        while(b%3==0)
        {
                b/=3;
                b3++;
        }
        if(a==b && a2<=b2 && a3<=b3)
        {
                cout<<(b2-a2)+(b3-a3)<<"\n";
        }
        else
        {
                cout<<"-1\n";
        }
        return 0;
}
/**

**/