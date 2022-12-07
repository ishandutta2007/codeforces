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
        vector <char> st;
        for(int a=0; a<s.size(); a++)
        {
            if(s[a]=='A') st.push_back('A');
            else
            {
                if(st.size()) st.pop_back();
                else st.push_back('B');
            }
        }
        cout<<st.size()<<"\n";
    }
}