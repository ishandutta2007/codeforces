#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, r;
    cin>>n>>r;
    int ar[1<<n];
    long long su=0;
    for(int a=0; a<(1<<n); a++)
    {
        scanf("%d", &ar[a]);
        su+=ar[a];
    }
    printf("%.8f\n", (1.0*su)/(1<<n));
    for(int a=0; a<r; a++)
    {
        int p, va;
        scanf("%d%d", &p, &va);
        su-=ar[p], ar[p]=va, su+=ar[p];
        printf("%.8f\n", (1.0*su)/(1<<n));
    }
}