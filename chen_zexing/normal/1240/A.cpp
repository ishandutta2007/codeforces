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
int p[200005],x,a,y,b,n;
long long c[200005],nd;
int check(int cnt){
    for(int i=1;i<=cnt;i++) c[i]=0;
    for(int i=a;i<=cnt;i+=a) c[i]+=x;
    for(int i=b;i<=cnt;i+=b) c[i]+=y;
    sort(c+1,c+cnt+1,greater<int>());
    long long tot=0;
    for(int i=1;i<=cnt;i++) tot+=1LL*p[i]*c[i];
    return tot>=nd;
}
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&p[i]),p[i]/=100;
        cin>>x>>a>>y>>b;
        cin>>nd;
        sort(p+1,p+n+1,greater<int>());
        int l=1,r=n+1;
        while(l<r){
            int mid=(l+r)/2;
            if(check(mid)) r=mid;
            else l=mid+1;
        }
        printf("%d\n",l>n?-1:l);
    }
    return 0;
}
//
/// 
//01
//