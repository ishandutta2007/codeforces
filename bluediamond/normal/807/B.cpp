#include <bits/stdc++.h>
using namespace std;
int p,x,y;
bool f(int val)
{
    int i=(val/50)%475;
    for(int j=1;j<=25;j++)
    {
        i=(i*96+42)%475;
        if(26+i==p)
            return 1;
    }
    return 0;
}
struct data
{
    int val,cost;
};
queue<data>q;
int main()
{
    cin>>p>>x>>y;
    int cost=0;
    while(x<y)
    {
        x+=100;
        cost++;
    }
    ///mergem in jos
    for(int i=x;i>=y;i-=50)
    {
        if(f(i))
        {
            cout<<cost;
            return 0;
        }
    }
    while(1)
    {
        if(f(x))
        {
            cout<<cost;
            return 0;
        }
        cost++;
        if(f(x+50))
        {
            cout<<cost;
            return 0;
        }
        x+=100;
    }
    return 0;
}
/**

**/