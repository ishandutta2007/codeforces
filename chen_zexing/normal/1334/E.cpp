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
long long gcd(long long a,long long b){
    return b==0?a:gcd(b,a%b);
}
struct fac{
    long long x;
    int cnt;
};
long long mod=998244353;
long long c[105][105];
unordered_map<long long,int>mp;
int main() {
    c[0][0]=c[1][0]=c[1][1]=1;
    for(int i=2;i<=100;i++){
        c[i][0]=1;
        for(int j=1;j<=i;j++) c[i][j]=c[i-1][j]+c[i-1][j-1],c[i][j]%=mod;
    }
    int T=1;
    //cin>>T;
    while(T--) {
        long long n;
        scanf("%lld",&n);
        int q;
        scanf("%d",&q);
        for(long long i=1,x,y;i<=q;i++){
            scanf("%lld%lld",&x,&y);
            long long t=gcd(x,y);
            long long temp=x/t;
            vector <fac> v;
            long long cnt=1,tot=0,ans=1;
            //cout<<temp<<endl;
            if(temp!=1) {
                if(mp[temp]) cnt=mp[temp];
                else {
                    long long o=temp;
                    for (int j = 2; 1LL * j * j <= temp; j++) {
                        if (temp % j == 0) {
                            int tt = 0;
                            while (temp % j == 0) temp /= j, tt++;
                            v.push_back(fac{j, tt});
                        }
                    }
                    if (temp > 2) v.push_back(fac{temp, 1});
                    for (int j = 0; j < v.size(); j++) tot += v[j].cnt;
                    for (int j = 0; j < v.size(); j++) cnt = cnt * c[tot][v[j].cnt] % mod, tot -= v[j].cnt;
                    mp[o]=cnt;
                }
            }
            ans*=cnt;
            temp=y/t;
            cnt=1,tot=0;
            v.clear();
            if(temp!=1){
                if(mp[temp]) cnt=mp[temp];
                else {
                    long long o=temp;
                    for (int j = 2; 1LL * j * j <= temp; j++) {
                        if (temp % j == 0) {
                            int tt = 0;
                            while (temp % j == 0) temp /= j, tt++;
                            v.push_back(fac{j, tt});
                        }
                    }
                    if (temp > 2) v.push_back(fac{temp, 1});
                    for (int j = 0; j < v.size(); j++) tot += v[j].cnt;
                    for (int j = 0; j < v.size(); j++) cnt = cnt * c[tot][v[j].cnt] % mod, tot -= v[j].cnt;
                    mp[o]=cnt;
                }
            }
            printf("%lld\n",ans*cnt%mod);
        }
    }
    return 0;
}