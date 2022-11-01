#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    int x=abs(a-c);
    int y=abs(b-d);
    printf("%d\n",x+y-min(x,y));
    return 0;
}