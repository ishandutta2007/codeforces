#include <iostream>
using namespace std;
struct fint
{
    int st,dr;
};
fint v1[200005];
fint v2[200005];
int main()
{
    int n,m,i;
    long long mi,ma,best=0;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>v1[i].st>>v1[i].dr;
    cin>>m;
    for(i=1;i<=m;i++)
        cin>>v2[i].st>>v2[i].dr;
    /// Sah - Info
    mi=99999999999;
    ma=0;
    for(i=1;i<=n;i++)
        if(v1[i].dr<mi)
            mi=v1[i].dr;
    for(i=1;i<=m;i++)
        if(v2[i].st>ma)
            ma=v2[i].st;
    if(best<ma-mi)
        best=ma-mi;
    ///Info - Sah
    mi=99999999999;
    ma=0;
    for(i=1;i<=m;i++)
        if(v2[i].dr<mi)
            mi=v2[i].dr;
    for(i=1;i<=n;i++)
        if(v1[i].st>ma)
            ma=v1[i].st;
    if(best<ma-mi)
        best=ma-mi;
    ///
    cout<<best;
    return 0;
}