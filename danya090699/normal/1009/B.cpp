#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    int q1=0, fo=0;
    for(int a=0; a<s.size(); a++) if(s[a]=='1') q1++;
    for(int a=0; a<s.size(); a++)
    {
        if(s[a]!='1')
        {
            if(s[a]=='2' and fo==0)
            {
                for(int b=0; b<q1; b++) cout<<"1";
                fo=1;
            }
            cout<<s[a];
        }
    }
    if(fo==0)
    {
        for(int b=0; b<q1; b++) cout<<"1";
    }
}