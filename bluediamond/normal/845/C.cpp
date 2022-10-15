#include <iostream>
#include <algorithm>
using namespace std;
struct fint
{
    int l,r;
};
fint v[200005];
bool cmp(fint a,fint b)
{
    return a.l<b.l;
}
int main()
{
    int n,i,dr1=-1,dr2=-1;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>v[i].l>>v[i].r;
    sort(v+1,v+n+1,cmp);
    for(i=1;i<=n;i++)
    {
        if(dr1<v[i].l)
        {
            dr1=v[i].r;
            continue;
        }
        if(dr2<v[i].l)
        {
            dr2=v[i].r;
            continue;
        }
        cout<<"NO";
        return 0;
    }
    cout<<"YES";
    return 0;
}