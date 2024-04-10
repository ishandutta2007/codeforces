#include <iostream>
using namespace std;
const int hmax=1000000;
int n,v[hmax+5];
int t1[hmax+5],t2[hmax+5];
int sum=0;
void slove1()
{
    int y=0;
    for(int i=1;i<=n+1;i++)
    {
        int ystart=y;
        for(int j=1;j<=v[i];j++)
            t1[++y]=ystart;
    }
    for(int i=1;i<=y;i++)
        cout<<t1[i]<<" ";
    cout<<"\n";
}
void slove2()
{
    int y=0,s=0,st=0;
    for(int i=1;i<=n+1;i++)
    {
        if(v[i]>=2 and v[i-1]>=2)
            break;
        st++;
        int ystart=y;
        for(int j=1;j<=v[i];j++)
            t2[++y]=ystart;
    }
    int poz1=y-1,poz2=y;
    ///rezolvam st+1
    t2[++y]=poz1;
    for(int i=2;i<=v[st+1];i++)
        t2[++y]=poz2;
    for(int i=st+2;i<=n+1;i++)
    {
        int ystart=y;
        for(int j=1;j<=v[i];j++)
            t2[++y]=ystart;
    }
    for(int i=1;i<=y;i++)
        cout<<t2[i]<<" ";
}
int main()
{
    cin>>n;
    for(int i=1;i<=n+1;i++)
        cin>>v[i];
    bool ok=0;
    for(int i=1;i<=n;i++)
        if(v[i]>=2 and v[i+1]>=2)
            ok=1;
    if(ok==0)
    {
        cout<<"perfect";
        return 0;
    }
    cout<<"ambiguous\n";
    slove1();
    slove2();
    return 0;
}