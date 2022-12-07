#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[2][n];
    for(int i=0; i<2; i++)
    {
        for(int a=0; a<n; a++)
        {
            scanf("%d", &ar[i][a]);
            if(a) ar[i][a-1]-=ar[i][a];
        }
        sort(ar[i], ar[i]+n-1);
    }
    bool ok=1;
    for(int a=0; a<n; a++) if(ar[0][a]!=ar[1][a]) ok=0;
    if(ok) cout<<"Yes";
    else cout<<"No";
}