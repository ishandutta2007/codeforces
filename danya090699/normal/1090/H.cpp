#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n-1];
    char s[n+2];
    scanf("%s", s);
    for(int a=0; a+1<n; a++) ar[a]=(s[a]!=s[a+1]);
    int pref[18][n-1];
    for(int i=0; i<18; i++)
    {
        for(int a=0; a<n-1; a++)
        {
            pref[i][a]=ar[a];
            if(a-(1<<i)>=0) pref[i][a]+=pref[i][a-(1<<i)];
        }
    }
    int q;
    cin>>q;
    for(int a=0; a<q; a++)
    {
        int l, r, an=0;
        scanf("%d%d", &l, &r);
        for(int i=1; (1<<i)<=(r-l+1); i++)
        {
            int q=(r-l+1)>>i, q1=pref[i][r-(1<<(i-1))];
            if(l-1-(1<<(i-1))>=0) q1-=pref[i][l-1-(1<<(i-1))];
            an+=min(q1, q-q1);
        }
        printf("%d\n", (an+1)>>1);
    }
}