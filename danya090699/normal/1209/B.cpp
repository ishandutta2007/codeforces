#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=0, st=0;
    cin>>n;
    string s;
    cin>>s;
    int ar[n][2];
    for(int a=0; a<n; a++) cin>>ar[a][0]>>ar[a][1];
    for(int a=0; a<1000; a++)
    {
        int q=0;
        for(int b=0; b<n; b++)
        {
            if(a<ar[b][1]) q+=(s[b]-'0');
            else q+=(((a-ar[b][1])/ar[b][0])%2)^(s[b]-'0')^1;
        }
        an=max(an, q);
    }
    cout<<an;
}