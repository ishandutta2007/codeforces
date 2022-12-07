#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    int ok=0, n=s.size();
    for(int a=1; a<n; a++) if(s[a]=='1') ok=1;
    int an=n/2+n%2;
    if(n&1 and ok==0) an--;
    cout<<an;
}