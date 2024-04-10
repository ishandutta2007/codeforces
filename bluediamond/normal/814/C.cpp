#include <bits/stdc++.h>

using namespace std;

int r()
{
    int aux;
    cin>>aux;
    return aux;
}

const int N=1500;

int n;
string a;
int dp[26][N+1],dif[N+1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>a;
    for(int c=0;c<26;c++)
    {
        for(int i=1;i<=n;i++)
            if(a[i-1]-'a'!=c)
                dif[i]=1;
            else
                dif[i]=0;
        for(int i=1;i<=n;i++)
            dif[i]+=dif[i-1];
        for(int l=1;l<=n;l++)
        {
            int st=1;
            for(int dr=1;dr<=n;dr++)
            {
                while(dif[dr]-dif[st-1]>l)
                    st++;
                dp[c][l]=max(dp[c][l],dr-st+1);
            }
        }
    }
    int q=r();
    while(q--)
    {
        int l=r();
        cin.get();
        char ch=cin.get();
        cout<<dp[ch-'a'][l]<<"\n";
    }
    return 0;
}