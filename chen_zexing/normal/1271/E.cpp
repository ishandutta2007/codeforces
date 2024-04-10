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
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        long long n,k;
        cin>>n>>k;
        long long l,r;
        //odd
        l=0,r=(n-1)/2;
        while(l<r){
            long long mid=(l+r)>>1;
            mid++;
            long long v=mid*2+1;
            long long now=2,cnt=1;
            v*=2;
            while(v+now-1<=n){
                cnt+=now;
                v*=2;
                now*=2;
            }
            if(v<=n) cnt+=n-v+1;
            if(cnt>=k) l=mid;
            else r=mid-1;
        }
        long long ans1=l*2+1;
        //even
        l=1,r=n/2;
        while(l<r){
            long long mid=(l+r)>>1;
            mid++;
            long long v=mid*2;
            long long now=2,cnt=0;
            while(v+now-1<=n){
                cnt+=now;
                v*=2;
                now*=2;
            }
            if(v<=n) cnt+=n-v+1;
            if(cnt>=k) l=mid;
            else r=mid-1;
        }
        long long ans2=l*2;
        long long v=ans2;
        long long now=2,cnt=0;
        while(v+now-1<=n){
            cnt+=now;
            v*=2;
            now*=2;
        }
        if(v<=n) cnt+=n-v+1;
        if(cnt<k) ans2=0;
        cout<<max(ans1,ans2)<<endl;
    }
    return 0;
}