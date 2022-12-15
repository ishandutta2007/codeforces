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
        int a,b;
        cin>>a>>b;
        if(a==b){
            puts("0");
            continue;
        }
        if(a>b) swap(a,b);
        if(a*2>=b){
            int tar=b-a;
            printf("%d\n",a%tar==0?0:tar-a%tar);
            continue;
        }
        int ans=INT_MAX;
        for(int i=1;i*i<=b-a;i++)
            if((b-a)%i==0){
                if(i>=a) ans=min(ans,i-a);
                if((b-a)/i>=a) ans=min(ans,(b-a)/i-a);
            }
        cout<<ans<<endl;
    }
    return 0;
}
//
/// 
//01
//