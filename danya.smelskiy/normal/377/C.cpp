#include <bits/stdc++.h>
using namespace std;


int n,m;
int a[1005];
int num[1005];
char tt[1005];
int dp[(1<<20)+5];
int kol[(1<<20)+5];

inline bool cmp(int a,int b){
    return a>b;
}
int main(){
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+n+1,cmp);
    cin>>m;
    for (int i=0;i<m;++i) {
        cin>>tt[i]>>num[i];
    }
    for (int i=0;i<(1<<m);++i)
        for (int j=0;j<m;++j)
            kol[i]+=((i&(1<<j)) ? 1 : 0);
    for (int i=(1<<m)-2;i>=0;--i) {
        if (num[kol[i]]==1) dp[i]=-1e9;
        else dp[i]=1e9;
        for (int j=0;j<m;++j)
        if (!(i&(1<<j))) {
            int res=dp[(i^(1<<j))];
            if (tt[kol[i]]=='p') res+=(num[kol[i]]==1 ? a[j+1] : -a[j+1]);
            if (num[kol[i]]==1) dp[i]=max(dp[i],res);
            else dp[i]=min(dp[i],res);
        }
    }
    cout<<dp[0];
}