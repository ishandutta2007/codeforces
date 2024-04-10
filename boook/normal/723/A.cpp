#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,x[3];
    while(scanf("%d%d%d",&x[0],&x[1],&x[2])==3)
    {
        sort(x,x+3);
        printf("%d\n",x[2]-x[0]);
    }
    return 0;
}