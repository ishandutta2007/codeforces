#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, ok=0;
    string s;
    cin>>n>>s;
    map <char, int> ma;
    for(int a=0; a<n; a++) ma[s[a]]++;
    for(auto it=ma.begin(); it!=ma.end(); it++)
    {
        if((*it).second>1)  ok=1;
    }
    if(n==1) cout<<"Yes";
    else
    {
        if(ok) cout<<"Yes";
        else cout<<"No";
    }

}