#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int ar[n][m], an[n], fo=-1, su=0;
    for(int a=0; a<n; a++)
    {
        an[a]=1;
        for(int b=0; b<m; b++)
        {
            scanf("%d", &ar[a][b]);
            if(ar[a][b]!=ar[a][0]) fo=a;
        }
    }
    for(int a=0; a<n; a++) if(a!=fo) su^=ar[a][0];
    if(fo!=-1)
    {
        for(int b=0; b<m; b++)
        {
            if(su^ar[fo][b])
            {
                su^=ar[fo][b];
                an[fo]=b+1;
                break;
            }
        }
    }
    if(su)
    {
        cout<<"TAK\n";
        for(int a=0; a<n; a++) cout<<an[a]<<" ";
    }
    else cout<<"NIE";
}