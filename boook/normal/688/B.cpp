#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while(cin>>s)
    {
        cout<<s;
        for(int i=s.size()-1;i>=0;i--)
            cout<<s[i];
        cout<<endl;
    }
    return 0;
}