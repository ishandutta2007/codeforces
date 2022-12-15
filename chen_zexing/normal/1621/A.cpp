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
using namespace std;
int main() {
    int T = 1;
    cin >> T;
    while(T--) {
        int n,k;
        cin>>n>>k;
        if(k*2-1>n) puts("-1");
        else{
            for(int i=1;i<=n;i++,puts(""))
                for(int j=1;j<=n;j++){
                    if(i==j&&i%2&&(i+1)/2<=k) printf("R");
                    else printf(".");
                }
        }
    }
    return 0;
}