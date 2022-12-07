#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int q[20];
    for(int a=0; a<20; a++) q[a]=0;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        for(int b=0; b<20; b++) if(x&(1<<b)) q[b]++;
    }
    long long an=0;
    for(int a=0; a<n; a++)
    {
        int x=0;
        for(int b=0; b<20; b++)
        {
            if(q[b])
            {
                x+=(1<<b);
                q[b]--;
            }
        }
        an+=1ll*x*x;
    }
    cout<<an;
}