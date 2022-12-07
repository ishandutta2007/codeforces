#include <bits/stdc++.h>
using namespace std;
void err()
{
    cout<<":(";
    exit(0);
}
main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    vector <char> sp;
    int r=0;
    for(int a=0; a<s.size(); a++)
    {
        if(s[a]!='a') sp.push_back(s[a]);
        else r=a+1;
    }
    int n=sp.size();
    if(n&1) err();
    if(r+n/2>s.size()) err();
    for(int a=0; a<n/2; a++) if(sp[a]!=sp[a+n/2]) err();
    cout<<s.substr(0, s.size()-n/2);
}