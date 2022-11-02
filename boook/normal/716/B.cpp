#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
#define MAX 100000
string s;
int L,R;
int dp[30];
bool F()
{
    if(s.size()<26)return 0;
    memset(dp,0,sizeof dp);
    int q=0,have=0;
    for(int i=0;i<26;i++)
    {
        if(s[i]=='?')q++;
        else if(dp[s[i]-'A']==0)dp[s[i]-'A']++,have++;
        else dp[s[i]-'A']++;
    }
    if(have+q==26)
    {
        L=0,R=25;return 1;
    }
    for(int i=26;i<s.size();i++)
    {
        if(s[i-26]=='?')q--;
        else if(dp[s[i-26]-'A']==1)dp[s[i-26]-'A']--,have--;
        else dp[s[i-26]-'A']--;

        if(s[i]=='?')q++;
        else if(dp[s[i]-'A']==0)dp[s[i]-'A']++,have++;
        else dp[s[i]-'A']++;
//        cout<<have<<"  "<<q<<endl;
        if(have+q==26)
        {
            L=i-25,R=i;
            return 1;
        }
    }
    return 0;
}
int main()
{

    while(cin>>s)
    {
//        cout<<s.size()<<endl;
        if(F()==0)puts("-1");
        else
        {
            for(int i=0;i<L;i++)
            {
                if(s[i]=='?')cout<<"A";
                else cout<<s[i];
            }
            for(int i=L,q=0;i<=R;i++)
            {
                while(q<=24 && dp[q]!=0)q++;
                if(s[i]!='?')cout<<s[i];
                else
                {
                    cout<<char('A'+q);
                    dp[q]=1;
                }
            }
            for(int i=R+1;i<s.size();i++)
            {
                if(s[i]=='?')cout<<"A";
                else cout<<s[i];
            }
            cout<<endl;
//            cout<<"ehrbv ans"<<endl;
        }
    }
    return 0;
}