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
int main() {
    int T=1;
    //cin>>T;
    while(T--) {
        long long n,p,w,d;
        cin>>n>>p>>w>>d;
        int f=0;
        for(int i=0;i<w;i++){
            if(1LL*i*d>p) break;
            if(i>n) break;
            if((p-1LL*i*d)%w==0){
                if(i+(p-1LL*i*d)/w>n) continue;
                f=1;
                printf("%lld %d %lld\n",(p-1LL*i*d)/w,i,n-(p-1LL*i*d)/w-i);
                break;
            }
        }
        if(f) continue;
        for(int i=0;i<d;i++){
            if(1LL*i*w>p) break;
            if(i>n) break;
            if((p-1LL*i*w)%d==0){
                if(i+(p-1LL*i*w)/d>n) continue;
                f=1;
                printf("%d %lld %lld\n",i,(p-1LL*i*w)/d,n-(p-1LL*i*w)/d-i);
                break;
            }
        }
        if(f==0) puts("-1");
    }
    return 0;
}