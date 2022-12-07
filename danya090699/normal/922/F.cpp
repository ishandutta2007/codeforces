#include <bits/stdc++.h>
using namespace std;
const int sz=3e5+10;
int q[sz], pref[sz], an[sz];
vector <int> pr;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, fo=0, qq, x;
    cin>>n>>k;
    for(int a=1; a<=n; a++)
    {
        pref[a]=pref[a-1]+q[a];
        if(q[a]==1) pr.push_back(a);
        for(int b=a+a; b<=n; b+=a) q[b]++;
        if(pref[a]>=k)
        {
            qq=a, x=a;
            if(pref[a]>k)
            {
                k=pref[a]-k;
                int ok=1;
                if(pr.size()<k) ok=0;
                else
                {
                    if(pr[pr.size()-k]<=a/2) ok=0;
                }
                if(ok)
                {
                    qq-=k;
                    while(k)
                    {
                        an[pr.back()]=1, pr.pop_back(), k--;
                    }
                }
                else
                {
                    bool dp[a+1][k+1];
                    for(int b=0; b<=a; b++) for(int c=0; c<=k; c++) dp[b][c]=0;
                    dp[a/2][0]=1;
                    for(int b=a/2+1; b<=a; b++)
                    {
                        for(int c=0; c<=k; c++)
                        {
                            if(dp[b-1][c])
                            {
                                dp[b][c]=1;
                                if(c+q[b]<=k) dp[b][c+q[b]]=1;
                            }
                        }
                    }
                    int cu=k;
                    for(int b=a; b>a/2; b--)
                    {
                        if(dp[b-1][cu]==0)
                        {
                            an[b]=1, qq--, cu-=q[b];
                        }
                    }
                }
            }
            fo=1;
            break;
        }
    }
    if(fo==0) cout<<"No";
    else
    {
        cout<<"Yes\n"<<qq<<"\n";
        for(int a=1; a<=x; a++) if(an[a]==0) cout<<a<<" ";
    }
}