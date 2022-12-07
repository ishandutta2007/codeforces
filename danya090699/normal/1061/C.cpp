#include <bits/stdc++.h>
using namespace std;
const int sz=1e6+10, mod=1e9+7;
int dp[sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    dp[0]=1;
    int n;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        vector <int> de, add;
        for(int b=1; b*b<=x; b++)
        {
            if(x%b==0)
            {
                de.push_back(b);
                if(b!=x/b) de.push_back(x/b);
            }
        }
        for(int b=0; b<de.size(); b++)
        {
            int y=de[b];
            add.push_back(dp[y-1]);
        }
        for(int b=0; b<de.size(); b++) dp[de[b]]=(dp[de[b]]+add[b])%mod;
    }
    int an=0;
    for(int a=1; a<sz; a++) an=(an+dp[a])%mod;
    cout<<an;
}