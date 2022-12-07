#include <bits/stdc++.h>
using namespace std;
int x, y, l[666][2], q[2][2];
bool mov(int dx, int dy)
{
    x+=dx, y+=dy;
    bool fo=0;
    for(int a=0; a<666; a++) if(l[a][0]==x and l[a][1]==y) fo=1;
    if(fo) x-=dx;
    cout<<x<<" "<<y<<"\n";
    int k, nx, ny;
    cin>>k>>nx>>ny;
    if(k==-1) return 1;
    if(k==0) exit(1);
    k--;
    l[k][0]=nx, l[k][1]=ny;
    return 0;
}
int main()
{
    cin>>x>>y;
    for(int a=0; a<666; a++) cin>>l[a][0]>>l[a][1];
    while(x<500)
    {
        if(mov(1, 0)) return 0;
    }
    while(x>500)
    {
        if(mov(-1, 0)) return 0;
    }
    while(y<500)
    {
        if(mov(0, 1)) return 0;
    }
    while(y>500)
    {
        if(mov(0, -1)) return 0;
    }
    for(int a=0; a<666; a++)
    {
        q[l[a][0]/500][l[a][1]/500]++;
    }
    int dx=1, dy=1, fo=0;
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            if(q[i][j]<=166)
            {
                if(i) dx=-1;
                if(j) dy=-1;
                fo=1;
                break;
            }
        }
        if(fo) break;
    }
    while(1)
    {
        if(mov(dx, dy)) return 0;
    }
}