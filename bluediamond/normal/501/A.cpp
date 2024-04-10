#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef long double ld;

int gt(int p,int t)
{
    return max(3*p/10,p-p*t/250);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int x=gt(a,c);
    int y=gt(b,d);
    if(x==y)
    {
        cout<<"Tie\n";
    }
    else
    {
        if(x<y)
        {
            cout<<"Vasya\n";
        }
        else
        {
            cout<<"Misha\n";
        }
    }

    return 0;
}
/**


**/