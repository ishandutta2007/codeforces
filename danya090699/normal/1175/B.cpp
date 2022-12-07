#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, inf=(1ll<<32), an=0;
    cin>>n;
    vector <int> st;
    st.push_back(1);
    for(int a=0; a<n; a++)
    {
        string s;
        cin>>s;
        if(s=="for")
        {
            int x;
            cin>>x;
            st.push_back(min(st.back()*x, inf));
        }
        if(s=="end") st.pop_back();
        if(s=="add")
        {
            an=min(inf, an+st.back());
        }
    }
    if(an==inf) cout<<"OVERFLOW!!!";
    else cout<<an;
}