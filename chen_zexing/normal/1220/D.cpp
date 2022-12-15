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
long long a[200005];
int cnt[105],c[200005];
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for(int i=1;i<=n;i++){
            int t=0;
            long long p=a[i];
            while(p%2==0&&p) p>>=1,t++;
            c[i]=t,cnt[t]++;
        }
        int ans=0,p;
        for(int i=0;i<100;i++){
            if(ans<cnt[i])
                ans=cnt[i],p=i;
        }
        cout<<n-ans<<endl;
        for(int i=1;i<=n;i++) if(c[i]!=p) printf("%lld ",a[i]);
    }
    return 0;
}