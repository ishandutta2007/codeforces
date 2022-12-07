#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;
        int q[2]={0, 0};
        for(int a=0; a<s.size(); a++) q[s[a]-'0']++;
        if(min(q[0], q[1])&1) cout<<"DA\n";
        else cout<<"NET\n";
    }
}