#pragma GCC optimize("Ofast,unroll-loops")
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
        int n,l,r;
        scanf("%d%d%d",&n,&l,&r);
        int f=1;
        for(int i=1;i<=n;i++) if(l/i==r/i&&l%i) f=0;
        puts(f?"YES":"NO");
        if(f){
            for(int i=1;i<=n;i++){
                int d=l/i*i;
                if(d<l) d+=i;
                printf("%d%c",d,i==n?'\n':' ');
            }
        }
    }
    return 0;
}
//unordered_map
//cf