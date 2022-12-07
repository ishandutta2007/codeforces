#include <bits/stdc++.h>
using namespace std;
bool us[10];
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int a=0; a<n; a++)
    {
        if(s[a]=='L')
        {
            for(int b=0; ; b++)
            {
                if(us[b]==0)
                {
                    us[b]=1;
                    break;
                }
            }
        }
        else if(s[a]=='R')
        {
            for(int b=9; ; b--)
            {
                if(us[b]==0)
                {
                    us[b]=1;
                    break;
                }
            }
        }
        else us[s[a]-'0']=0;
    }
    for(int a=0; a<10; a++) cout<<us[a];
}