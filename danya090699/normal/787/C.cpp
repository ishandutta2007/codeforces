#include <bits/stdc++.h>
using namespace std;
struct el
{
    int pos, pl;
};
el nel;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, q1, q2;
    cin>>n;
    vector <int> go[2];
    cin>>q1;
    for(int a=0; a<q1; a++)
    {
        int x;
        cin>>x;
        go[0].push_back(x);
    }
    cin>>q2;
    for(int a=0; a<q2; a++)
    {
        int x;
        cin>>x;
        go[1].push_back(x);
    }
    int dp[n][2], q[n][2];
    for(int a=0; a<n; a++)
    {
        dp[a][0]=0, dp[a][1]=0, q[a][0]=q1, q[a][1]=q2;
    }
    dp[0][0]=2, dp[0][1]=2;
    queue <el> qu;
    nel.pos=0, nel.pl=0;
    qu.push(nel);
    nel.pos=0, nel.pl=1;
    qu.push(nel);
    while(qu.size()>0)
    {
        int qq=qu.size();
        for(int a=0; a<qq; a++)
        {
            el cu=qu.front();
            int pos=cu.pos, pl=cu.pl, ri=0;
            if(pl==0) ri=1;
            if(dp[pos][pl]==2)
            {
                for(int b=0; b<go[ri].size(); b++)
                {
                    int pos2=pos-go[ri][b];
                    if(pos2<0) pos2+=n;
                    if(dp[pos2][ri]==0)
                    {
                        dp[pos2][ri]=1;
                        nel.pos=pos2, nel.pl=ri;
                        qu.push(nel);
                    }
                }
            }
            else
            {
                for(int b=0; b<go[ri].size(); b++)
                {
                    int pos2=pos-go[ri][b];
                    if(pos2<0) pos2+=n;
                    if(dp[pos2][ri]==0)
                    {
                        q[pos2][ri]--;
                        if(q[pos2][ri]==0)
                        {
                            dp[pos2][ri]=2;
                            nel.pos=pos2, nel.pl=ri;
                            qu.push(nel);
                        }
                    }
                }
            }
            qu.pop();
        }
    }
    for(int a=1; a<n; a++)
    {
        if(dp[a][0]==0) cout<<"Loop";
        else if(dp[a][0]==1) cout<<"Win";
        else cout<<"Lose";
        cout<<" ";
    }
    cout<<"\n";
    for(int a=1; a<n; a++)
    {
        if(dp[a][1]==0) cout<<"Loop";
        else if(dp[a][1]==1) cout<<"Win";
        else cout<<"Lose";
        cout<<" ";
    }
}