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
#include <list>
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
unordered_map <long long,int> mp,f;
int x[1005],y[1005];
int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,cnt=0;
        long long ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++){
                int xx=x[j]-x[i],yy=y[j]-y[i],g=gcd(abs(xx),abs(yy));
                xx/=g,yy/=g;
                if(xx<0) xx=-xx,yy=-yy;
                if(xx==0) yy=1;
                if(yy==0) xx=1;
                int d;
                if(xx==0) d=x[i];
                else if(yy==0) d=y[i];
                else d=y[i]*xx-x[i]*yy;
                //cout<<x[i]<<" "<<y[i]<<" "<<x[j]<<" "<<y[j]<<" "<<xx<<" "<<yy<<endl;
                //cout<<d<<" "<<y[j]*xx-x[j]*yy<<endl;
                //assert(y[j]*xx-x[j]*yy==d);
                if(f[20000000000LL*d+xx*100000LL+yy]) continue;
                //cout<<i<<" "<<j<<endl;
                f[20000000000LL*d+xx*100000LL+yy]=1;
                ans+=mp[xx*100000LL+yy],cnt++;
                mp[xx*100000LL+yy]++;
            }
        printf("%lld\n",1LL*cnt*(cnt-1)/2-ans);
    }
    return 0;
}
//
/// 
//01
//