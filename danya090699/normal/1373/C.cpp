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
        int mi=0, x=0;
        long long an=s.size();
        for(int a=0; a<s.size(); a++)
        {
            if(s[a]=='+') x++;
            else x--;
            if(x<mi) an+=a+1, mi=x;
        }
        cout<<an<<"\n";
    }
}