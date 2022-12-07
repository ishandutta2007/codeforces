#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, q1, q2, ok=1;
    cin>>n>>q1>>q2;
    int an[n][n];
    for(int a=0; a<n; a++) for(int b=0; b<n; b++) an[a][b]=0;
    if(q1>=2)
    {
        if(q2==1)
        {
            for(int a=0; a+1<n-(q1-1); a++)
            {
                an[a][a+1]=1, an[a+1][a]=1;
            }
        }
        else ok=0;
    }
    else
    {
        for(int a=0; a<n; a++) for(int b=0; b<n; b++) if(a!=b) an[a][b]=1;
        if(q2>=2)
        {
            for(int a=0; a+1<n-(q2-1); a++)
            {
                an[a][a+1]=0, an[a+1][a]=0;
            }
        }
        else
        {
            if(n==1 or n>=4)
            {
                for(int a=0; a+1<n; a++)
                {
                    an[a][a+1]=0, an[a+1][a]=0;
                }
            }
            else ok=0;
        }
    }
    if(ok)
    {
        printf("YES\n");
        for(int a=0; a<n; a++)
        {
            for(int b=0; b<n; b++) printf("%d", an[a][b]);
            printf("\n");
        }
    }
    else printf("NO\n");
}