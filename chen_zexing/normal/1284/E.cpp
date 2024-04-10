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
long double x[2505],y[2505];
const long double pi=acos(-1.0L);
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
        long long ans=1LL*n*(n-1)*(n-2)*(n-3)*(n-4)/24;
        for(int i=1;i<=n;i++){
            vector <long double> v;
            for(int j=1;j<=n;j++)
                if(i!=j)
                    v.push_back(atan2(x[j]-x[i],y[j]-y[i]));
            sort(v.begin(),v.end());
            int now=0;
            for(int j=0;j<n-1;j++){
                while(now<j+n-1){
                    long double temp=(v[now%(n-1)]-v[j]);
                    if(temp<0) temp+=2*pi;
                    if(temp<pi) now++;
                    else break;
                }
                ans-=1LL*(now-j-1)*(now-j-2)*(now-j-3)/6;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}