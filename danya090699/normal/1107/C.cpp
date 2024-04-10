#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    int ar[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    string s;
    cin>>s;
    int yk=0, an=0;
    while(yk<n)
    {
        char sy=s[yk];
        int st=yk;
        multiset <int> se;
        se.insert(0);
        while(yk<n)
        {
            if(s[yk]==sy) yk++;
            else break;
        }
        sort(ar+st, ar+yk, greater <int>());
        for(int a=st; a<min(yk, st+k); a++) an+=ar[a];
    }
    cout<<an;
}