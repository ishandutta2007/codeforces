#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, yk=0, ti=0, an=-1;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    sort(ar, ar+n);
    int m;
    cin>>m;
    for(int a=0; a<m; a++)
    {
        int l, r;
        cin>>l>>r;
        while(yk<n)
        {
            if(ti+ar[yk]<=r)
            {
                if(yk==n-1) an=max(l, ti+ar[yk]);
                ti+=ar[yk];
                yk++;
            }
            else break;
        }
    }
    cout<<an;
}