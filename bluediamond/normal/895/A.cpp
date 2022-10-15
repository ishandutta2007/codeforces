#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <iomanip>
#include <cstring>
#include <cctype>
using namespace std;
#define ll long long
int n,v[365],mi=360;
int f(int st,int dr)
{
    int su=0;
    for(int i=st;i<=dr;i++)
        su+=v[i];
    return su;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    ///alegem st<=dr
    for(int st=1;st<=n;st++)
        for(int dr=st;dr<=n;dr++)
        {
            ///cout<<st<<" "<<dr<<" , "<<f(st,dr)<<"\n";
            mi=min(mi,abs(f(st,dr)-(360-f(st,dr))));
        }
    ///alegem dr<=st
    for(int dr=1;dr<=n;dr++)
        for(int st=1;st<=n;st++)
        {
            int val=f(1,dr)+f(st,n);
            mi=min(mi,abs(val-(360-val)));
        }
    cout<<mi;
    return 0;
}
/**

**/