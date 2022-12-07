#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=3e5+10;
int q[sz];
main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=0;
    cin>>n;
    vector <int> st;
    for(int a=0; a<n; a++)
    {
        string s;
        cin>>s;
        int mi=0, va=0;
        for(int b=0; b<s.size(); b++)
        {
            if(s[b]=='(') va++;
            else va--;
            mi=min(mi, va);
        }
        if(mi==0) st.push_back(va);
        if(va<=0 and mi==va) q[-va]++;
    }
    for(int a=0; a<st.size(); a++) an+=q[st[a]];
    cout<<an;
}