#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int n;
        scanf("%d", &n);
        pair <pair <int, int>, int> ar[n];
        int an[n];
        for(int a=0; a<n; a++)
        {
            scanf("%d%d", &ar[a].first.first, &ar[a].first.second);
            ar[a].second=a;
            an[a]=2;
        }
        sort(ar, ar+n);
        int rg=ar[0].first.second, fo=0;
        an[ar[0].second]=1;
        for(int a=1; a<n; a++)
        {
            if(ar[a].first.first>rg)
            {
                for(int b=0; b<n; b++) printf("%d ", an[b]);
                fo=1;
                break;
            }
            else
            {
                an[ar[a].second]=1;
                rg=max(rg, ar[a].first.second);
            }
        }
        if(fo==0) printf("-1");
        printf("\n");
    }
}