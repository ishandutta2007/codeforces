#include <bits/stdc++.h>
using namespace std;

string s;
int dp[8005];
int p[8005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    int n=s.size();
    for (int i=1;i<=n;++i)
        dp[i]=i+1;
    for (int i=0;i<n;++i) {
        string ss="";
        for (int j=i+1;j<=n;++j)
            ss+=s[j-1];
        p[0]=0;
        for (int j=1;j<ss.size();++j) {
            int k=p[j-1];
            while (k && ss[j]!=ss[k]) k=p[k-1];
            if (ss[k]==ss[j]) ++k;
            p[j]=k;
        }
        for (int j=0;j<ss.size();++j) {
            int k=i+j+1;
            int len=k-i;
            int z=len-p[j];
            int len2=0;
            if (len%z==0) len2=z;
            else len2=len;
            int kol=len2;
            z=len/len2;
            while (z) {
                ++kol;
                z/=10;
            }
            dp[k]=min(dp[k],dp[i]+kol);
        }
    }
    cout<<dp[n];
}