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
int main() {
    int T;
    cin>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        long long l,r;
        l=max(a[1]-k+2,0LL),r=a[1]+k;
        int f=1;
        for(int i=2;i<n;i++){
            l=max(l,a[i]+1);
            r=min(r,a[i]+k);
            //cout<<l<<" "<<r<<endl;
            if(l>r){
                f=0;
                break;
            }
            l-=k-1,r+=k-1;
            //cout<<l<<" "<<r<<endl;
        }
        if(a[n]+1<l||a[n]+1>r) f=0;
        if(f) puts("YES");
        else puts("NO");
    }
    return 0;
}