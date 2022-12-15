#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
long long mod=998244353;
long long qpow(long long a,long long b){
    long long ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}
long long inv(long long x){
    return qpow(x,mod-2);
}
long long p[300005][2];
string s[300005];
vector <int> l[300005],r[300005],up[300005],down[300005];
int main() {
    std::ios::sync_with_stdio(false);
    int T=1;
    //cin>>T;
    while(T--){
        p[0][0]=1,p[0][1]=0;
        p[1][0]=inv(2),p[1][1]=inv(2);
        for(int i=2;i<=300000;i++){
            if(i%2==0){
                p[i][1]=(p[i-2][1]+inv(qpow(2,i)))%mod;
                p[i][0]=(1-p[i][1]+mod)%mod;
            }
            else{
                p[i][0]=(p[i-2][0]+inv(qpow(2,i)))%mod;
                p[i][1]=(1-p[i][0]+mod)%mod;
            }
        }
        int n,m,w=0;
        cin>>n>>m;
        for(int i=0;i<n;i++) cin>>s[i];
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                l[i].push_back(0),r[i].push_back(0),up[i].push_back(0),down[i].push_back(0),w+=(s[i][j]=='o');
        for(int i=1;i<n;i++)
            for(int j=0;j<m;j++)
                up[i][j]=s[i-1][j]=='o'?up[i-1][j]+1:0;
        for(int i=n-2;i>=0;i--)
            for(int j=0;j<m;j++)
                down[i][j]=s[i+1][j]=='o'?down[i+1][j]+1:0;
        for(int j=1;j<m;j++)
            for(int i=0;i<n;i++)
                l[i][j]=s[i][j-1]=='o'?l[i][j-1]+1:0;
        for(int j=m-2;j>=0;j--)
            for(int i=0;i<n;i++)
                r[i][j]=s[i][j+1]=='o'?r[i][j+1]+1:0;
        long long ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m-1;j++){
                if(s[i][j]=='o'&&s[i][j+1]=='o'){
                    int t1=l[i][j],t2=r[i][j+1];
                    ans+=inv(2)*((1LL*p[t1][0]*p[t2][1]%mod+1LL*p[t1][1]*p[t2][0]%mod)%mod)%mod;
                    ans%=mod;
                    ans+=p[t1][0]*p[t2][0]%mod;
                    ans%=mod;
                }
            }
        for(int i=0;i<n-1;i++)
            for(int j=0;j<m;j++){
                if(s[i][j]=='o'&&s[i+1][j]=='o'){
                    int t1=up[i][j],t2=down[i+1][j];
                    ans+=inv(2)*((1LL*p[t1][0]*p[t2][1]%mod+1LL*p[t1][1]*p[t2][0]%mod)%mod)%mod;
                    ans%=mod;
                    ans+=p[t1][0]*p[t2][0]%mod;
                    ans%=mod;
                }
            }
        ans*=inv(4),ans%=mod;
        ans*=qpow(2,w),ans%=mod;
        printf("%lld\n",ans);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp