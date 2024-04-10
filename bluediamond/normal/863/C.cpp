#include <iostream>
using namespace std;
int mata[5][5];
int matb[5][5];
struct fint
{
    int a,b,win;
};
fint r1[1000],r[1000];
long long nr1,nr,a,b,n;
void nextgen()
{
    int a2=mata[a][b],b2=matb[a][b];
    a=a2;
    b=b2;
}
int win(int a,int b)
{
    if(a==b)
        return 0;
    if(a==1)
    {
        if(b==2)
            return 2;
        return 1;
    }
    if(a==2)
    {
        if(b==1)
            return 1;
        return 2;
    }
    if(a==3)
    {
        if(b==1)
            return 2;
        return 1;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);


    cin>>n>>a>>b;
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            cin>>mata[i][j];
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            cin>>matb[i][j];
    nr1=1;
    r1[1].a=a;
    r1[1].b=b;
    while(1)
    {
        nr1++;
        nextgen();
        r1[nr1].a=a;
        r1[nr1].b=b;
        bool ok=0;
        for(int i=1;i<nr1;i++)
            if(r1[i].a==a and r1[i].b==b)
            {
                nr1--;
                for(int j=i;j<=nr1;j++)
                {
                    nr++;
                    r[nr].a=r1[j].a;
                    r[nr].b=r1[j].b;
                }
                ok=1;
                break;
            }
        if(ok==1)
            break;
    }
    for(int i=1;i<=nr1;i++)
        r1[i].win=win(r1[i].a,r1[i].b);
    for(int i=1;i<=nr;i++)
        r[i].win=win(r[i].a,r[i].b);
    if(n<=nr1)
    {
        long long sca=0,scb=0;
        for(int i=1;i<=n;i++)
        {
            if(r1[i].win==1)
                sca++;
            if(r1[i].win==2)
                scb++;
        }
        cout<<sca<<" "<<scb;
        return 0;
    }
    long long sca=0,scb=0;
    for(int i=1;i<=nr1;i++)
    {
        if(r1[i].win==1)
            sca++;
        if(r1[i].win==2)
            scb++;
    }
    n-=nr1;
    long long x=n/nr,y=n%nr,sa=0,sb=0;
    for(int i=1;i<=nr;i++)
    {
        if(r[i].win==1)
            sa++;
        if(r[i].win==2)
            sb++;
    }
    sca+=sa*x;
    scb+=sb*x;
    for(int i=1;i<=y;i++)
    {
        if(r[i].win==1)
            sca++;
        if(r[i].win==2)
            scb++;
    }
    cout<<sca<<" "<<scb;
    return 0;
}