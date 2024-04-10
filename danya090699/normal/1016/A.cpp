#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, os;
    cin>>n>>m;
    os=m;
    for(int a=0; a<n; a++)
    {
        int q, an=0;
        scanf("%d", &q);
        if(q>=os)
        {
            q-=os, an++;
            an+=q/m, os=m-q%m;
        }
        else os-=q;
        if(a==n-1 and os==0) an--;
        printf("%d ", an);
    }
}