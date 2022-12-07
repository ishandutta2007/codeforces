//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=(1<<20);
int q[sz];
void build(int nu, int le)
{
    if(le>=0)
    {
        build(nu*2, le-1);
        build(nu*2+1, le-1);
        q[nu]=q[nu*2]+q[nu*2+1];
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, z=0;
    cin>>n>>m;
    for(int a=0; a<sz; a++) q[a]=0;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        int cu=1;
        for(int b=18; b>=0; b--)
        {
            if((x&(1<<b))==0) cu*=2;
            else cu=cu*2+1;
        }
        q[cu]=1;
    }
    build(1, 18);
    for(int a=0; a<m; a++)
    {
        int x, cu=1, an=0;
        scanf("%d", &x);
        z^=x;
        for(int b=18; b>=0; b--)
        {
            int y=(z&(1<<b));
            if(y>0) y=1;
            if(q[cu*2+y]==(1<<b))
            {
                y^=1, an+=(1<<b);
            }
            cu=cu*2+y;
        }
        printf("%d\n", an);
    }
}