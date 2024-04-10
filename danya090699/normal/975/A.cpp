#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    set <string> sp;
    for(int a=0; a<n; a++)
    {
        string s;
        cin>>s;
        set <char> se;
        for(int b=0; b<s.size(); b++) se.insert(s[b]);
        string t;
        for(auto it=se.begin(); it!=se.end(); it++) t.push_back(*it);
        sp.insert(t);
    }
    cout<<sp.size();
}