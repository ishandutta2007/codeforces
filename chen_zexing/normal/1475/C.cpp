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
int x[200005],y[200005];
int cnta[200005],cntb[200005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int a,b,n;
        cin>>a>>b>>n;
        for(int i=1;i<=a;i++) cnta[i]=0;
        for(int i=1;i<=b;i++) cntb[i]=0;
        for(int i=1;i<=n;i++) scanf("%d",&x[i]),cnta[x[i]]++;
        for(int i=1;i<=n;i++) scanf("%d",&y[i]),cntb[y[i]]++;
        long long ans=0;
        for(int i=1;i<=n;i++){
            ans+=n-cnta[x[i]]-cntb[y[i]]+1;
            //cout<<ans<<endl;
        }
        printf("%lld\n",ans/2);
    }
    return 0;
}