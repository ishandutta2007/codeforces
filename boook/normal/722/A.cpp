#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    while(scanf("%d",&t)==1)
    {
        string s;
        cin>>s;
        int x=(s[0]-'0')*10+(s[1]-'0');

        if(t==24)
        {
            if(x>=t)s[0]='0';
        }
        else if(t==12)
        {
            if(x==0)s[0]='1';
            else if(x>t)
            {
                if(x%10==0)s[0]='1';
                else s[0]='0';
            }
        }
        int y=(s[3]-'0')*10+(s[4]-'0');


        if(y>=60)s[3]='0';
        cout<<s<<endl;
    }
    return 0;
}