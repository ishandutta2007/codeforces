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
int a[200005],f[200005];
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
multiset <int> s[20005];
int c[20005];
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int cnt=0;
        for(int i=2;i<=200000;i++){
            if(f[i]==0){
                f[i]=++cnt;
                for(int j=i*2;j<=200000;j+=i) f[j]=-1;
            }
        }
        int n,q;
        cin>>n>>q;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int g=a[1];
        for(int i=2;i<=n;i++) g=gcd(g,a[i]);
        long long ans=g,mod=1000000007;
        for(int i=1;i<=n;i++){
            a[i]/=g;
            for(int j=2;j*j<=a[i];j++){
                while(a[i]%j==0){
                    if(s[f[j]].find(i)==s[f[j]].end()) c[f[j]]++;
                    a[i]/=j,s[f[j]].insert(i);
                }
            }
            if(a[i]>1){
                int j=a[i];
                if(s[f[j]].find(i)==s[f[j]].end()) c[f[j]]++;
                a[i]/=j,s[f[j]].insert(i);
            }
        }
        while(q--){
            int i,x;
            scanf("%d%d",&i,&x);
            for(int j=2;j*j<=x;j++){
                while(x%j==0){
                    if(s[f[j]].find(i)==s[f[j]].end()) c[f[j]]++;
                    x/=j,s[f[j]].insert(i);
                    if(c[f[j]]==n){
                        ans*=j,ans%=mod;
                        for(int k=1;k<=n;k++){
                            s[f[j]].erase(s[f[j]].find(k));
                            if(s[f[j]].find(k)==s[f[j]].end()) c[f[j]]--;
                        }
                    }
                }
            }
            if(x>1){
                int j=x;
                if(s[f[j]].find(i)==s[f[j]].end()) c[f[j]]++;
                x/=j,s[f[j]].insert(i);
                if(c[f[j]]==n){
                    ans*=j,ans%=mod;
                    for(int k=1;k<=n;k++){
                        s[f[j]].erase(s[f[j]].find(k));
                        if(s[f[j]].find(k)==s[f[j]].end()) c[f[j]]--;
                    }
                }
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
//
/// 