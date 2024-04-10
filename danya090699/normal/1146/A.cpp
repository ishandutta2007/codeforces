#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    int q=0;
    for(int a=0; a<s.size(); a++) if(s[a]=='a') q++;
    cout<<min(int(s.size()), q*2-1);
}