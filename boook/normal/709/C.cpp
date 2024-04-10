#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while(cin>>s)
    {
        int i=0;
        while(i<=s.size() && s[i]=='a')i++;
        if(i==s.size())s[s.size()-1]='z';
        else
        {
            while(i<=s.size() && s[i]!='a')s[i]--,i++;
        }
        cout<<s<<endl;
    }
    return 0;
}