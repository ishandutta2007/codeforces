#include <iostream>
#include <algorithm>
using namespace std;
struct fint
{
    int x,i;
};
fint v[105];
bool cmp(fint a,fint b)
{
    return a.x>b.x;
}
int main()
{
    int n,i,j,u;
    cin>>n;
    for(i=1;i<=n;i++)
        {
        cin>>v[i].x;
        v[i].i=i;
        }
    sort(v+2,v+n+1,cmp);
    u=1;
    for(i=1;i<=n;i++)
    {
        if(u<i)
        {
            cout<<-1;
            return 0;
        }
        for(j=1;j<=v[i].x;j++)
        {
            u++;
            if(u==n)
                break;
        }
        if(u==n)
            break;
    }
    cout<<n-1<<"\n";
    u=1;
    for(i=1;i<=n;i++)
    {
        if(u<i)
        {
            cout<<-1;
            return 0;
        }
        for(j=1;j<=v[i].x;j++)
        {
            cout<<v[i].i<<" "<<v[++u].i<<"\n";
            if(u==n)
                return 0;
        }
    }
    return 0;
}