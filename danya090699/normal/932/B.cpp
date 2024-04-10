#include <bits/stdc++.h>
using namespace std;
const int sz=1e6+10;
int ar[sz], pref[sz][10];
int main()
{
    //freopen("input.txt", "r", stdin);
    for(int a=0; a<10; a++) ar[a]=a;
    for(int a=10; a<sz; a++)
    {
        int x=a, pr=1;
        while(x)
        {
            if(x%10) pr*=x%10;
            x/=10;
        }
        ar[a]=ar[pr];
    }
    for(int a=0; a<10; a++) pref[0][a]=0;
    for(int a=0; a+1<sz; a++)
    {
        for(int b=0; b<10; b++) pref[a+1][b]=pref[a][b];
        pref[a+1][ar[a+1]]++;
    }
    int q;
    cin>>q;
    for(int a=0; a<q; a++)
    {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        l--;
        printf("%d\n", pref[r][k]-pref[l][k]);
    }
}