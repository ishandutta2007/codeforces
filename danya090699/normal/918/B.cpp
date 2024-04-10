#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    map <string, string> ma;
    for(int a=0; a<n; a++)
    {
        string s, t;
        cin>>s>>t;
        ma[t]=s;
    }
    for(int a=0; a<m; a++)
    {
        string s, t;
        cin>>s>>t;
        cout<<s<<" "<<t<<" #"<<ma[t.substr(0, t.size()-1)]<<"\n";
    }
}