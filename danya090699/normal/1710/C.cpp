#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int main() {
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    int dp[2][8][8];
    for(int i=0; i<2; i++) for(int m1=0; m1<8; m1++) for(int m2=0; m2<8; m2++) dp[i][m1][m2]=0;
    dp[0][7][7]=1;
    for(int a=0; a<s.size(); a++)
    {
        int zif = s[a]-'0';
        for(int m1=0; m1<8; m1++)
        {
            for(int m2=0; m2<8; m2++)
            {
                for(int madd=0; madd<8; madd++)
                {
                    int val[3] = {madd&1 ? 1 : 0, madd&2 ? 1 : 0, madd&4 ? 1 : 0}, ok=1, new_m1=0;
                    for(int p=0; p<3; p++)
                    {
                        if(m1&(1<<p))
                        {
                            if(zif==val[p]) new_m1 += (1<<p);
                            if(zif<val[p]) ok=0;
                        }
                    }
                    if(ok)
                    {
                        int new_m2 = ((val[0]^val[1])<<0)+((val[0]^val[2])<<1)+((val[1]^val[2])<<2);
                        if(new_m2) new_m2 &= m2;
                        else new_m2 = m2;

                        dp[1][new_m1][new_m2] = (dp[1][new_m1][new_m2] + dp[0][m1][m2])%mod;
                    }
                }
            }
        }
        for(int m1=0; m1<8; m1++)
        {
            for(int m2=0; m2<8; m2++)
            {
                dp[0][m1][m2] = dp[1][m1][m2];
                dp[1][m1][m2] = 0;
            }
        }

    }
    int an=0;
    for(int m1=0; m1<8; m1++) an=(an+dp[0][m1][0])%mod;
    cout<<an;
}