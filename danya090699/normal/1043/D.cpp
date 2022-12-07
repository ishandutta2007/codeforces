#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int ar[m][n];
    for(int a=0; a<m; a++)
    {
        for(int b=0; b<n; b++)
        {
            scanf("%d", &ar[a][b]), ar[a][b]--;
        }
    }
    int ne[n];
    for(int b=0; b+1<n; b++) ne[ar[0][b]]=ar[0][b+1];
    ne[ar[0][n-1]]=-1;
    for(int a=1; a<m; a++)
    {
        for(int b=0; b+1<n; b++)
        {
            if(ne[ar[a][b]]!=ar[a][b+1]) ne[ar[a][b]]=-1;
        }
        ne[ar[a][n-1]]=-1;
    }
    int yk=0;
    long long an=0;
    while(yk<n)
    {
        int q=1;
        while(ne[ar[0][yk]]!=-1) yk++, q++;
        an+=(1ll*q*(q-1))/2+q;
        yk++;
    }
    cout<<an;
}