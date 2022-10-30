#include <bits/stdc++.h>
using namespace std;

string s;
int n;
int cnt[30][30][5005];
long double ans[5005];
long double cnt2[100];
long double dp[30][5005];


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    n=s.size();
    s="#"+s;
    for (int i=1;i<=n;++i) {
        int last=(i%n)+1;
        int len=1;
        for (int j=1;j<n;++j) {
            ++cnt[s[i]-'a'][s[last]-'a'][len];
            ++len;
            ++last;
            if (last>n) last-=n;
        }
    }
    for (int i=1;i<=n;++i) {
        int last=(i%n)+1;
        int len=1;
        for (int j=1;j<n;++j) {
            if (cnt[s[i]-'a'][s[last]-'a'][len]==1) ++dp[s[i]-'a'][len];
            ++len;
            last++;
            if (last>n) last-=n;
        }
        ++cnt2[s[i]-'a'];
    }
    long double res=0;
    for (int i=0;i<26;++i) if (cnt2[i]>0) {
        long double res1=cnt2[i]/(long double)n;
        long double res2=0;
        for (int j=0;j<=n;++j) {
            long double res3=dp[i][j];
            res3/=(long double)cnt2[i];
            if (res3>res2) res2=res3;
        }
        res+=res1*res2;
    }
    cout<<fixed<<setprecision(6)<<res;

}