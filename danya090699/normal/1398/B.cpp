#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        vector <int> sp;
        int yk=0, an=0;
        while(yk<s.size())
        {
            sp.push_back(0);
            if(s[yk]=='1')
            {
                while(yk<s.size() and s[yk]=='1') yk++, sp.back()++;
            }
            else yk++;
        }
        sort(sp.begin(), sp.end(), greater <int>());
        for(int a=0; a<sp.size(); a+=2) an+=sp[a];
        cout<<an<<"\n";
    }
}