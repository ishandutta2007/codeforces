#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, yk=0;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    char sv[n-1];
    for(int a=0; a<n-1; a++) cin>>sv[a];
    while(yk<n)
    {
        int st=yk;
        while(yk+1<n)
        {
            if(sv[yk]=='1') yk++;
            else break;
        }
        yk++;
        sort(ar+st, ar+yk);
    }
    bool ok=1;
    for(int a=0; a<n; a++) if(ar[a]!=a+1) ok=0;
    if(ok) cout<<"YES";
    else cout<<"NO";
}