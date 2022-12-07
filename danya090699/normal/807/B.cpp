#include <bits/stdc++.h>
using namespace std;
int de(int a, int b)
{
    int re=a/b;
    if(a%b!=0) re++;
    return re;
}
int main()
{
    int p, x, y;
    cin>>p>>x>>y;
    int s=x-1000*50;
    if(s<y) s=x-(x-y)/50*50;
    for(s; s>=0; s+=50)
    {
        int i=(s/50)%475, fo=0;
        for(int b=0; b<25; b++)
        {
            i=(i*96+42)%475;
            if(26+i==p) fo=1;
        }
        if(fo)
        {
            if(s>x) cout<<de(s-x, 100);
            else cout<<0;
            break;
        }
    }
}