#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;

string s;
int n;
long long p[5011];
long long h[5011];
long long h2[5011];
short dp[5005][5005];
int ans[5005];
inline bool check(int l,int r){
    if (l==r) return true;
    int ll=(l+r-1)/2;
    long long hh=h[ll]-h[l-1];
    if (hh<0) hh+=md;
    int ll2=(l+r)/2;
    ++ll2;
    long long hh2=h2[ll2]-h2[r+1];
    if (hh2<0) hh2+=md;
    ll2=n-ll2+1;
    if (ll<ll2) hh=(hh*p[ll2-ll])%md;
    else hh2=(hh2*p[ll-ll2])%md;
    return hh==hh2;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    n=s.size();
    p[0]=1;
    for (int i=1;i<=n+5;++i)
        p[i]=(p[i-1]*31)%md;
    for (int i=1;i<=s.size();++i) {
        h[i]=(h[i-1]+((s[i-1]-'a'+1)*(p[i]))%md)%md;
    }
    for (int i=n;i>0;--i) {
        h2[i]=(h2[i+1]+((s[i-1]-'a'+1)*(p[n-i+1]))%md)%md;
    }
    int sz=1;
    while ((1<<sz)<n) sz++;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n-i+1;++j) {
                for (int k=1;k<=sz;++k) {
                    if (k==1) {
                        if (check(j,j+i-1)) dp[j][j+i-1]=1;
                        else break;
                        ++ans[1];
                        continue;
                    }
                    int ll=(j+j+i-1-1)/2;
                    int ll2=(j+j+i-1)/2+1;
                    if (ll<j && ll2>j+i-1) continue;
                    if (dp[j][ll]>=k-1 && dp[ll2][j+i-1]>=k-1) {
                        dp[j][j+i-1]=k;
                        ++ans[k];
                    }
                }
        }
    }
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
}