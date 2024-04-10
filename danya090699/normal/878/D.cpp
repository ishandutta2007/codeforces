#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+100;
int ar[sz][13], ar2[sz][13], i, qq;
bool comp(int a, int b){return ar[i][a]<ar[i][b];}
bitset <4096> el[sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, q;
    cin>>n>>k>>q;
    qq=k;
    for(int a=0; a<k; a++)
    {
        for(int b=0; b<n; b++)
        {
            scanf("%d", &ar[b][a]), ar2[b][a]=a;
        }
    }
    for(i=0; i<n; i++)
    {
        sort(ar2[i], ar2[i]+k, comp);
        int mask=(1<<k)-1;
        for(int a=0; a<k; a++)
        {
            for(int b=a; b<k; b++) el[ar2[i][b]][mask]=1;
            mask-=(1<<ar2[i][a]);
        }
    }
    for(int a=0; a<q; a++)
    {
        int t, x, y;
        scanf("%d%d%d", &t, &x, &y);
        x--, y--;
        if(t==1)
        {
            el[qq]=el[x]|el[y], qq++;
        }
        if(t==2)
        {
            el[qq]=el[x]&el[y], qq++;
        }
        if(t==3)
        {
            int mask=(1<<k)-1;
            for(i=0; i<k; i++)
            {
                if(el[x][mask]==0) break;
                mask-=(1<<ar2[y][i]);
            }
            printf("%d\n", ar[y][ar2[y][i-1]]);
        }
    }
}