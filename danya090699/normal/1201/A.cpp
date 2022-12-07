#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, an=0;
    cin>>n>>m;
    string s[n];
    for(int a=0; a<n; a++) cin>>s[a];
    for(int a=0; a<m; a++)
    {
        int va;
        cin>>va;
        int q[5]={0, 0, 0, 0, 0}, be=0;
        for(int b=0; b<n; b++) q[s[b][a]-'A']++, be=max(be, q[s[b][a]-'A']);
        an+=be*va;
    }
    cout<<an;
}