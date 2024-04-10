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
        int n=s.size(), an=n;
        for(int i=0; i<10; i++)
        {
            for(int j=0; j<10; j++)
            {
                int x[2]={i, j}, y=0, q=0;
                for(int a=0; a<n; a++)
                {
                    if(s[a]-'0'==x[y]) q++, y^=1;
                }
                if(i!=j and q&1) q--;
                an=min(an, n-q);
            }
        }
        cout<<an<<"\n";
    }
}