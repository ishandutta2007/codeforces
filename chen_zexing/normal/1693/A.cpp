#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
#include <assert.h>
#include <random>
using namespace std;
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,fl=1,f=0;
        scanf("%d",&n);
        long long now=0;
        for(int i=1,x;i<=n;i++){
            scanf("%d",&x);
            now+=x;
            if(now==0) f=2;
            else if(f==2){
                if(now>0) f++,fl=0;
            }
            if(now<0) fl=0;
        }
        if(now!=0) fl=0;
        puts(fl?"YES":"NO");
    }
    return 0;
}