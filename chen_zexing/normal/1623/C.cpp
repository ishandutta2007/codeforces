#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <string.h>
using namespace std;
long long a[200005],b[200005];
int main() {
    int T = 1;
    cin >> T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        int l=0,r=1e9;
        while(l<r){
            int mid=(l+r)/2+1,f=1;
            for(int i=1;i<=n;i++) b[i]=a[i];
            for(int i=n;i>=3;i--){
                if(b[i]<mid) f=0;
                long long d=min(a[i]/3,(b[i]-mid)/3);
                b[i]-=d*3,b[i-1]+=d,b[i-2]+=d*2;
            }
            if(b[1]<mid||b[2]<mid) f=0;
            if(f) l=mid;
            else r=mid-1;
        }
        cout<<l<<endl;
    }
    return 0;
}