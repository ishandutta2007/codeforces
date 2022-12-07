#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int d, n, m;
    cin>>d>>n>>m;
    n=max(n, m);
    n+=2;
    int pref[2][n], suf[2][n];
    for(int i=0; i<2; i++) for(int a=0; a<n; a++) pref[i][a]=0, suf[i][a]=0;
    int ar[d][2][2];
    for(int a=0; a<d; a++)
    {
        scanf("%d%d%d%d", &ar[a][0][0], &ar[a][1][0], &ar[a][0][1], &ar[a][1][1]);
        for(int i=0; i<2; i++)
        {
            if(ar[a][i][0]>ar[a][i][1]) swap(ar[a][i][0], ar[a][i][1]);
            pref[i][ar[a][i][0]]++;
            suf[i][ar[a][i][1]]++;
        }
    }
    int an[2][2];
    for(int i=0; i<2; i++) for(int j=0; j<2; j++) cin>>an[i][j];
    for(int a=1; a<n; a++) for(int i=0; i<2; i++) pref[i][a]+=pref[i][a-1];
    for(int a=n-2; a>=0; a--) for(int i=0; i<2; i++) suf[i][a]+=suf[i][a+1];
    for(int a=0; a<d; a++)
    {
        int q[2][2];
        for(int i=0; i<2; i++)
        {
            q[i][0]=pref[i][ar[a][i][1]-1];
            q[i][1]=suf[i][ar[a][i][0]+1];
            if(ar[a][i][0]!=ar[a][i][1]) q[i][0]--, q[i][1]--;
        }
        bool ok=1;
        for(int i=0; i<2; i++) for(int j=0; j<2; j++) if(q[i][j]!=an[i][j]) ok=0;
        if(ok)
        {
            cout<<a+1;
            return 0;
        }
    }
    cout<<-1;
}