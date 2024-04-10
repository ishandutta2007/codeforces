#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
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
using namespace std;
int gcd(int a,int b){
    return a%b==0?b:gcd(b,a%b);
}
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int a,b,k;
        scanf("%d%d%d",&a,&b,&k);
        if(a>b) swap(a,b);
        int aa=a,bb=b;
        int t=gcd(a,b),ta=a/t,tb=b/t;
        int l=ta==1?1:2;
        if(a==b) l=0;
        int cnt=0;
        for(int i=2;i*i<=a;i++){
            if(a%i==0){
                while(a%i==0) a/=i,cnt++;
            }
        }
        if(a>1) cnt++;
        for(int i=2;i*i<=b;i++){
            if(b%i==0) while(b%i==0) b/=i,cnt++;
        }
        if(b>1) cnt++;
        //cout<<l<<" "<<cnt<<endl;
        if(k==1) puts(bb%aa==0&&bb!=aa?"YES":"NO");
        else puts(k<=cnt&&k>=l?"YES":"NO");
    }
    return 0;
}
//
/// 
//01
// 
//
//dp