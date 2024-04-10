#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
char s[1005];
int fa[2005],d[2005];
int find(int x){
    if(fa[x]==x) return fa[x];
    find(fa[x]),d[x]+=d[fa[x]],d[x]%=2,fa[x]=fa[fa[x]];
    return fa[x];
}
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
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n;
        long long ans=0;
        scanf("%s",s+1);
        n=strlen(s+1);
        for(int i=1;i<=n/2;i++) swap(s[i],s[n-i+1]);
        for(int i=1;i<n;i++){
            int f=1;
            for(int j=1;j<=n+i;j++) fa[j]=j,d[j]=0;
            for(int j=1;j<=i/2;j++){
                int x=find(n+j),y=find(n+i-j+1);
                if(x!=y) fa[y]=x,d[y]=d[n+j]^d[n+i-j+1];
                else if(d[n+i-j+1]!=d[n+j]) f=0;
            }
            for(int j=1;j<=n/2;j++){
                int x=find(j),y=find(n-j+1);
                if(x!=y) fa[y]=x,d[y]=d[j]^d[n-j+1];
                else if(d[n-j+1]!=d[j]) f=0;
            }
            for(int j=1;j<=i;j++){
                int x=find(j),y=find(n+j);
                if(x!=y){
                    if(s[j]=='?') continue;
                    else if(s[j]=='1') fa[y]=x,d[y]=d[j]^d[n+j]^1;
                    else fa[y]=x,d[y]=d[j]^d[n+j];
                }
                else{
                    if(s[j]=='?') continue;
                    else if(s[j]=='1'){
                        if(d[j]==d[n+j]) f=0;
                    }
                    else if(s[j]=='0'){
                        if(d[j]!=d[n+j]) f=0;
                    }
                }
            }
            //for(int j=1;j<=n+i;j++) cout<<find(j)<<" "<<d[j]<<endl;
            for(int j=i+1;j<n;j++){
                int x=find(j),y=find(n);
                if(x!=y){
                    if(s[j]=='?') continue;
                    else if(s[j]=='1') fa[y]=x,d[y]=d[n]^d[j];
                    else fa[y]=x,d[y]=d[n]^d[j]^1;
                }
                else{
                    if(s[j]=='?') continue;
                    else if(s[j]=='1'){
                        if(d[j]!=d[n]) f=0;
                    }
                    else if(d[j]==d[n]) f=0;
                }
            }
            //for(int j=1;j<=n+i;j++) cout<<find(j)<<" "<<d[j]<<endl;
            //puts("");
            int x=find(n+i),y=find(n);
            if(x!=y) fa[y]=x,d[y]=d[n+i]^d[n];
            else if(d[n]!=d[n+i]) f=0;
            if(!f) continue;
            int cnt=0;
            for(int j=1;j<=n+i;j++) if(fa[j]==j) cnt++;
            ans+=qpow(2,cnt-1),ans%=mod;
            //cout<<i<<" "<<ans<<endl;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
//
/// 
//01
//