#include <iostream>
#include <algorithm>
using namespace std;
struct fint
{
    int x,i;
};
bool cmp(fint a,fint b)
{
    return a.x>b.x;
}
fint v[105];
int sol[105];
int main()
{
    int n,i,m;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>v[i].x;
        v[i].i=i;
    }
    sort(v+1,v+n+1,cmp);
    for(i=1;i<=n;i++)
    {
        int sc=v[i].x/2;
        if(v[i].x%2)
            sc++;
        sol[v[i].i]=sc;
        m-=sc;
    }
    if(m<0)
    {
        cout<<-1;
        return 0;
    }
    v[0].x=v[1].x;
    for(i=1;i<=n;i++)
    {
        if(v[i].x==v[i-1].x)
        {
            int x=min(m,v[i].x-sol[v[i].i]);
            sol[v[i].i]+=x;
            m-=x;
            if(m==0)
                break;
        }
        else
        {
            int x=min(m,v[i].x-sol[v[i].i]);
            int y=min(m,sol[v[i-1].i]-1),z=min(x,y);
            sol[v[i].i]+=z;
            m-=z;
            if(m==0)
                break;
        }
    }
    if(m)
    {
        cout<<-1;
        return 0;
    }
    for(i=1;i<=n;i++)
        cout<<sol[i]<<" ";
    return 0;
}
///8 7 7 6
/*
4 4
2 3
1 1
*/
///6 5 5 4