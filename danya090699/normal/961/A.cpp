#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, q=0;
    cin>>n>>m;
    int ar[n];
    for(int a=0; a<n; a++) ar[a]=0;
    for(int a=0; a<m; a++)
    {
        int x, ok=1;
        cin>>x;
        ar[x-1]++;
        for(int b=0; b<n; b++) if(ar[b]==0) ok=0;
        if(ok)
        {
            q++;
            for(int b=0; b<n; b++) ar[b]--;
        }
    }
    cout<<q;
}