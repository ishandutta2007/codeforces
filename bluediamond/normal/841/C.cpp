#include <iostream>
#include <algorithm>
using namespace std;
struct fint
{
    int x,i;
};
fint v2[200005];
int v1[200005];
bool cmp1(fint a,fint b)
{
    return a.x<b.x;
}
bool cmp2(fint a,fint b)
{
    return a.i<b.i;
}
int main()
{
    int n,i;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>v1[i];
    for(i=1;i<=n;i++)
    {
        cin>>v2[i].x;
        v2[i].i=i;
    }
    sort(v1+1,v1+n+1);
    sort(v2+1,v2+n+1,cmp1);
    for(i=1;i<=n;i++)
        v2[n+1-i].x=v1[i];
    sort(v2+1,v2+n+1,cmp2);
    for(i=1;i<=n;i++)
        cout<<v2[i].x<<" ";
    return 0;
}