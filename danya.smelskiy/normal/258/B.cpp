#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;
int dp[100][2][100];
int kol[100];
string n;
int kol2[100];
int a[100];
long long ans[100];

void recurs(int x,int sum){
    if (x==6) {
        for (int i=0;i<10;++i)
            kol2[i]=0;
        for (int i=1;i<=6;++i){
            ++kol2[a[i]];
            if (kol2[a[i]]>kol[a[i]]) return;
        }
        long long res=1;
        for (int i=0;i<10;++i) {
            long long y=kol[i];
            for (int j=1;j<=kol2[i];++j){
                res=(res*y)%md;
                --y;
            }
        }
        ans[sum]=(ans[sum]+res)%md;
        return;
    }
    for (int i=0;i<10;++i) if (sum+i<10) {
        a[x+1]=i;
        recurs(x+1,sum+i);
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<n[0]-'0';++i)
        dp[1][1][ ((i==4 || i==7) ? 1 : 0) ]++;
    dp[1][0][((n[0]-'0'==4 || n[0]-'0'==7) ? 1 : 0)]=1;
    for (int i=1;i<n.size();++i)
        for (int j=0;j<2;++j)
    for (int k=0;k<=i;++k) if (dp[i][j][k]) {
        for (int z=0;z<10;++z) {
            if (j==1 || (j==0 && z<n[i]-'0')) {
                dp[i+1][1][k+(z==4 || z==7 ? 1 : 0)]+=dp[i][j][k];
            } else if (z==n[i]-'0') dp[i+1][0][k+(z==4 || z==7 ? 1 :0)]+=dp[i][j][k];
        }
    }
    for (int i=0;i<2;++i)
        for (int j=0;j<=n.size();++j)
            kol[j]+=dp[(int)n.size()][i][j];
    for (int i=1;i<=n.size();++i)
        for (int j=0;j<2;++j)
            for (int k=0;k<=n.size();++k)
                dp[i][j][k]=0;
    for (int i=1;i<=9;++i)
        dp[1][0][(i==4 || i==7) ? 1 : 0]++;
    for (int i=1;i<n.size()-1;++i)
        for (int j=0;j<=i;++j)
            for (int k=0;k<10;++k)
                dp[i+1][0][j+(k==4 || k==7 ? 1 : 0)]+=dp[i][0][j];
    for (int i=1;i<n.size();++i)
        for (int j=0;j<=i;++j)
            kol[j]+=dp[i][0][j];
    recurs(0,0);
    long long res=0;
    for (int i=1;i<=10;++i){
        for (int j=0;j<i;++j)
            res=(res+kol[i]*ans[j])%md;
    }
    cout<<res;
}