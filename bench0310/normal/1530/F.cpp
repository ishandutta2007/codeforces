#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int mod=31607;
    auto add=[&](int a,int b)->int{return a+b-(a+b>=mod?mod:0);};
    auto sub=[&](int a,int b)->int{return a-b+(a-b<0?mod:0);};
    auto mul=[&](int a,int b)->int{return (a*b)%mod;};
    const int inv=3973;
    int n;
    cin >> n;
    vector a(n,vector(n,int(0)));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> a[i][j];
            a[i][j]=mul(a[i][j],inv);
        }
    }
    vector<int> ctz((1<<n),-1);
    for(int m=1;m<(1<<n);m++)
    {
        for(int i=0;i<n;i++)
        {
            if(m&(1<<i))
            {
                ctz[m]=i;
                break;
            }
        }
    }
    vector col(n,vector((1<<n),int(1)));
    for(int j=0;j<n;j++)
    {
        for(int m=1;m<(1<<n);m++)
        {
            col[j][m]=mul(col[j][m^(1<<ctz[m])],a[ctz[m]][j]);
        }
    }
    vector<int> row(n,1);
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) row[i]=mul(row[i],a[i][j]);
    int res=0;
    int all=(1<<n)-1;
    for(int m=0;m<(1<<n);m++) //rows
    {
        int popcnt=0;
        for(int i=0;i<n;i++) if(m&(1<<i)) popcnt++;
        for(int one=0;one<2;one++) //main diagonal
        {
            for(int two=0;two<2;two++) //antidiagonal
            {
                int now=1;
                for(int i=0;i<n;i++) if(m&(1<<i)) now=mul(now,row[i]);
                vector<int> col_mask(n,all^m);
                if(one==1)
                {
                    for(int j=0;j<n;j++)
                    {
                        if(col_mask[j]&(1<<j)) //not yet taken
                        {
                            now=mul(now,a[j][j]);
                            col_mask[j]^=(1<<j);
                        }
                    }
                }
                if(two==1)
                {
                    for(int j=0;j<n;j++)
                    {
                        int i=n-1-j;
                        if(col_mask[j]&(1<<i)) //not yet taken
                        {
                            now=mul(now,a[i][j]);
                            col_mask[j]^=(1<<i);
                        }
                    }
                }
                array<int,2> dp={0,0};
                dp[(popcnt+one+two)&1]=now;
                for(int j=0;j<n;j++)
                {
                    array<int,2> ndp=dp; //don't take this column
                    //take this column
                    for(int x=0;x<2;x++) ndp[x]=add(ndp[x],mul(dp[1-x],col[j][col_mask[j]]));
                    dp=ndp;
                }
                res=add(res,dp[1]);
                res=sub(res,dp[0]);
//                cout << "[" << m << "," << one << "," << two << "]: " << dp[0] << " " << dp[1] << endl;
            }
        }
    }
    cout << add(res,1) << "\n";
    return 0;
}