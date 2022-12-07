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
        string s;
        cin>>s;
        vector <int> sp[2];
        for(int a=s.size()-1; a>=0; a--)
        {
            int i=s[a]-'0';
            sp[i%2].push_back(i);
        }
        while(sp[0].size() or sp[1].size())
        {
            int v0=10, v1=10;
            if(sp[0].size()) v0=sp[0].back();
            if(sp[1].size()) v1=sp[1].back();

            cout<<min(v0, v1);

            if(v0<v1) sp[0].pop_back();
            else sp[1].pop_back();
        }
        cout<<"\n";
    }
}