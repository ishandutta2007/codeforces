#include <bits/stdc++.h>
using namespace std;

int n;
int a[100];
bool dp[2][(1<<23)+5];
int msk[100];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=0;i<n;++i)
        cin>>a[i];
    int x=0,y=1;
    dp[x][1]=true;
    for (int i=1;i<n;++i) {
        swap(x,y);
        for (int j=0;j<i;++j) {
            msk[j]=0;
            for (int k=0;k<i;++k)
                if (a[j]+a[k]==a[i]) msk[j]|=(1<<k);
        }
        for (int j=0;j<(1<<i);++j)
            dp[x][j]=false;
        for (int j=1;j<(1<<i);++j) if (dp[y][j]){
            bool t=false;
            for (int k=0;k<i;++k)
            if ((j&(1<<k)) && (j&(msk[k]))) {
                t=true;
                break;
            }
            if (!t) continue;
            dp[x][(j|(1<<i))]=true;
            for (int k=0;k<i;++k)
            if (j&(1<<k)) {
                int msk2=(j^(1<<k));
                msk2=(msk2|(1<<i));
                dp[x][msk2]=true;
            }
        }
    }
    int ans=1e9;
    for (int i=1;i<(1<<n);++i)
    if (dp[x][i]) {
        int kol=0;
        for (int j=0;j<n;++j)
            if (i&(1<<j)) ++kol;
        ans=min(ans,kol);
    }
    cout<<(ans==1e9 ? -1 : ans);
}