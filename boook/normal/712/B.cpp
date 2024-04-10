#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while(cin>>s)
    {
        int L=0,R=0,U=0,D=0;
        for(int i=0;i<s.size();i++)
            if(s[i]=='L')L++;
            else if(s[i]=='R')R++;
            else if(s[i]=='U')U++;
            else if(s[i]=='D')D++;
            int y=min(L,R),k=min(U,D);
        L-=y,R-=y,U-=k,D-=k;
        if((L+R+U+D)%2==0)
        {
            int ans=0;
            L=max(L,R);R=0;
            U=max(U,D);D=0;
            if(L%2)L--,ans++,U--;
            printf("%d\n",ans+(L/2)+(U/2));
        }
        else puts("-1");
    }
    return 0;
}