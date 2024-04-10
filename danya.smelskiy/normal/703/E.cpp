#include <bits/stdc++.h>
using namespace std;

int n;
long long k;
long long a[1005];
vector<long long> v;
long long dp[10000];
map<long long,int> pos;
long long s[10000];
short pos1[10000005];
short pred[1005][7000];
inline long long GCD(long long a,long long b){
    while (a && b) {
        if (a>b) a%=b;
        else b%=a;
    }
    return a+b;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    long long mn=1e18;
    int pp=-1;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        if (a[i]<mn) {
            mn=a[i];
            pp=i;
        }
    }
    if (k==1) {
        cout<<1<<'\n'<<pp;
        return 0;
    }
    for (long long i=1;i*i<=k;++i) if (k%i==0) {
        v.push_back(i);
        if (i*i!=k) v.push_back(k/i);
    }
    sort(v.begin(),v.end());
    for (int i=0;i<v.size();++i) {
        if (v[i]<=1e7) pos1[v[i]]=i;
        else pos[v[i]]=i;
        dp[i]=1e9;
    }
    dp[0]=0;
    for (int i=1;i<=n;++i) {
        long long z=a[i];
        for (int j=v.size()-1;j;--j) {
            pred[i][j]=j;
            long long q=v[j]/GCD(a[i],v[j]);
            int x;
            if (q<=1e7) x=pos1[q];
            else x=pos[q];
            if (dp[x]+1<dp[j] || (dp[x]+1==dp[j] && s[x]+a[i]<s[j])) {
                dp[j]=dp[x]+1;
                s[j]=s[x]+a[i];
                pred[i][j]=x;
            }
        }
    }
    if (dp[v.size()-1]==1e9) {
        cout<<"-1";
        return 0;
    }
    cout<<dp[v.size()-1]<<'\n';
    k=v.size()-1;
    for (int i=n;i>0 && k>0;--i) {
        if (k>0 && pred[i][k]!=k) cout<<i<<" ";
        if (k>0) k=pred[i][k];
    }
}