#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    while(scanf("%d",&t)==1)
    {
        string s;
        cin>>s;s+="_";
        int ans[2]={0,0},q=0,c=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                if(q)
                {
                    if(c==0)ans[0]=max(ans[0],q);
                    else ans[1]++;
                }
                q=0,c=1;
            }
            else if(s[i]==')')
            {
                if(q)ans[c]++;
                q=0,c=0;
            }
            else if(s[i]=='_')
            {
                if(q)
                {
                    if(c==0)ans[0]=max(ans[0],q);
                    else ans[1]++;
                }
                q=0;
            }
            else if( (s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
            {
                q++;
            }
        }
        printf("%d %d\n",ans[0],ans[1]);
    }
    return 0;
}