#include <bits/stdc++.h>
using namespace std;
const int sz=5e3+10;
bool dp[sz][sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, v;
    cin>>n>>k>>v;
    dp[0][0]=1;
    int ar[n];
    for(int a=0; a<n; a++)
    {
        cin>>ar[a];
        for(int b=0; b<k; b++)
        {
            if(dp[a][b])
            {
                dp[a+1][(b+ar[a])%k]=1;
                dp[a+1][b]=1;
            }
        }
    }
    if(dp[n][v%k])
    {
        int cu=v%k, q1=0, q2=0;
        vector <int> sp, sp2;
        for(int a=n-1; a>=0; a--)
        {
            int ne=cu-(ar[a]%k);
            if(ne<0) ne+=k;
            if(dp[a][ne])
            {
                q1+=ar[a], cu=ne, sp.push_back(a);
            }
            else
            {
                q2+=ar[a], sp2.push_back(a);
            }
        }
        if(q1+(q2-q2%k)<v) cout<<"NO";
        else
        {
            cout<<"YES\n";
            for(int a=1; a<sp.size(); a++)
            {
                int nu=sp[a];
                if(ar[nu]>0) cout<<ar[nu]/k+(ar[nu]%k>0)<<" "<<nu+1<<" "<<sp[0]+1<<"\n";
            }
            for(int a=1; a<sp2.size(); a++)
            {
                int nu=sp2[a];
                if(ar[nu]>0) cout<<ar[nu]/k+(ar[nu]%k>0)<<" "<<nu+1<<" "<<sp2[0]+1<<"\n";
            }
            if(sp.size()==0) sp.push_back(sp2.back());
            if(sp2.size()==0) sp2.push_back(sp.back());
            if(q1>v)
            {
                cout<<(q1-v)/k<<" "<<sp[0]+1<<" "<<sp2[0]+1<<"\n";
            }
            if(q1<v)
            {
                cout<<(v-q1)/k<<" "<<sp2[0]+1<<" "<<sp[0]+1<<"\n";
            }
        }
    }
    else cout<<"NO";
}