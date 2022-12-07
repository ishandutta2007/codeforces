#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    int n=s.size();
    for(int a=n-1; a>=0; a--) s.push_back(s[a]);
    cout<<s;
}