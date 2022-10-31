#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    long long ansx=0,ansy=0;
    for(int i=0,x,y;i<2*n;i++)
    {
        scanf("%d%d",&x,&y);
        ansx+=x,ansy+=y;
    }
    printf("%lld %lld\n",ansx/n,ansy/n);
}