#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int suf[n+1][4], q[4]={0, 0, 0, 0};
    for(int i=0; i<4; i++) suf[n][i]=0;
    for(int a=n-1; a>=0; a--)
    {
        for(int i=0; i<4; i++) suf[a][i]=suf[a+1][i];
        if(s[a]=='U') suf[a][0]++;
        if(s[a]=='D') suf[a][1]++;
        if(s[a]=='R') suf[a][2]++;
        if(s[a]=='L') suf[a][3]++;
    }
    int x, y;
    cin>>x>>y;
    if(n>=abs(x)+abs(y))
    {
        if((n-abs(x)-abs(y))%2==0)
        {
            int an=1e9;
            for(int a=0; a<n; a++)
            {
                int lg=a-1, rg=n+1;
                while(rg-lg>1)
                {
                    int mid=(lg+rg)>>1;
                    int u=q[0]+suf[mid][0], d=q[1]+suf[mid][1], r=q[2]+suf[mid][2], l=q[3]+suf[mid][3];

                    //cout<<mid<<" "<<u<<" "<<d<<" "<<l<<" "<<r<<"\n";

                    if(abs(y-(u-d))+abs(x-(r-l))<=mid-a) rg=mid;
                    else lg=mid;
                }
                if(rg!=n+1) an=min(an, rg-a);

                //cout<<rg<<"\n";

                if(s[a]=='U') q[0]++;
                if(s[a]=='D') q[1]++;
                if(s[a]=='R') q[2]++;
                if(s[a]=='L') q[3]++;
            }
            cout<<an;
        }
        else cout<<-1;
    }
    else cout<<-1;

}