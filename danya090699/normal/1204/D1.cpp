#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    vector <int> st;
    for(int a=0; a<s.size(); a++)
    {
        if(s[a]=='0' and st.size() and s[st.back()]=='1') st.pop_back();
        else st.push_back(a);
    }
    for(int a=0; a<st.size(); a++) s[st[a]]='0';
    cout<<s;
}