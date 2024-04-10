#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    string s, t;
    cin>>s>>t;
    vector <string> ve;
    for(int a=1; a<=s.size(); a++)
    {
        for(int b=1; b<=t.size(); b++) ve.push_back(s.substr(0, a)+t.substr(0, b));
    }
    sort(ve.begin(), ve.end());
    cout<<ve[0];
}