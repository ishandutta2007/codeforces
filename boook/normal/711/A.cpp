#include<bits/stdc++.h>
using namespace std;
#define MAX 1100
int main()
{
    int t;
    string s[MAX];
    while(cin>>t)
    {
        for(int i=0;i<t;i++)cin>>s[i];
        int ans=0;
        for(int i=0;i<t;i++)
        {
            if(s[i][0]==s[i][1] && s[i][0]=='O')
            {s[i][0]='+',s[i][1]='+',ans=1;break;}
            if(s[i][3]==s[i][4] && s[i][3]=='O')
            {s[i][3]='+',s[i][4]='+',ans=1;break;}
        }
        if(!ans)puts("NO");
        else
        {
            puts("YES");
            for(int i=0;i<t;i++)
                cout<<s[i]<<endl;
        }
    }
    return 0;
}