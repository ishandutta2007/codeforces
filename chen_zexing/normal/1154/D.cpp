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
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,b,a,mxa;
        cin>>n>>b>>a;
        mxa=a;
        for(int i=1,t;i<=n;i++){
            scanf("%d",&t);
            if(!a&&!b){
                printf("%d\n",i-1);
                exit(0);
            }
            if(t==0){
                if(a) a--;
                else b--;
            }
            else{
                if(b&&a!=mxa) a++,b--;
                else a--;
            }
        }
        printf("%d\n",n);
    }
    return 0;
}
//
/// 
//01
//