#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string tmp(s.end()-2,s.end());
        if(tmp=="po")
            cout<<"FILIPINO\n";
        else{
            tmp=string(s.end()-4,s.end());
            if(tmp=="desu"||tmp=="masu") cout<<"JAPANESE\n";
            else cout<<"KOREAN\n";
        }
    }
}