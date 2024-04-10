#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int n, q=0, fo=0;
        cin>>n;
        for(int a=0; a<n; a++)
        {
            string s;
            cin>>s;
            if(s.size()%2) fo=1;
            for(int b=0; b<s.size(); b++) q+=s[b]-'0';
        }
        if(q%2 and fo==0) cout<<n-1<<"\n";
        else cout<<n<<"\n";
    }
}