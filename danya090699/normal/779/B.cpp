#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int k, an=0;
    cin>>s>>k;
    int n=s.size();
    for(int a=n-1; a>0; a--)
    {
        if(s[a]=='0') k--;
        else an++;
        if(k==0) break;
    }
    if(k==0) cout<<an;
    else cout<<s.size()-1;
}