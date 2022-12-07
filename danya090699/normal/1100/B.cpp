#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int q[n], qq=0;
    for(int a=0; a<n; a++) q[a]=0;
    for(int a=0; a<m; a++)
    {
        int x;
        scanf("%d", &x);
        x--;
        if(q[x]==0) qq++;
        q[x]++;
        if(qq==n)
        {
            for(int b=0; b<n; b++)
            {
                q[b]--;
                if(q[b]==0) qq--;
            }
            printf("1");
        }
        else printf("0");
    }
}