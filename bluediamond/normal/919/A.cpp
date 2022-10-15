#include <bits/stdc++.h>
using namespace std;
int n;
double m,a,b,best;
int main()
{
    cin>>n>>m>>a>>b;
    best=a/b;
    for(int i=2;i<=n;i++)
    {
        cin>>a>>b;
        if(a/b<best)
            best=a/b;
    }
    cout<<fixed<<setprecision(6)<<best*m;
    return 0;
}
/**

**/