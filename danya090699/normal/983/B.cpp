#include <bits/stdc++.h>
using namespace std;
const int sz=5e3+10;
int va[sz][sz], ma[sz][sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        scanf("%d", &va[1][a]);
        ma[1][a]=va[1][a];
    }
    for(int a=2; a<=n; a++)
    {
        for(int b=0; b+a<=n; b++) va[a][b]=va[a-1][b]^va[a-1][b+1];
    }
    for(int a=2; a<=n; a++)
    {
        for(int b=0; b+a<=n; b++)
        {
            ma[a][b]=max(va[a][b], max(ma[a-1][b], ma[a-1][b+1]));
        }
    }
    int q;
    cin>>q;
    for(int a=0; a<q; a++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        l--;
        printf("%d\n", ma[r-l][l]);
    }
}