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
int a[105];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,sum=0,f=0;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum+=a[i];
        for(int i=2;i*i<=sum;i++) if(sum%i==0) f=1;
        if(f){
            printf("%d\n",n);
            for(int i=1;i<=n;i++) printf("%d ",i);
            puts("");
        }
        else{
            int pos=-1;
            for(int i=1;i<=n;i++) if(a[i]%2) pos=i;
            printf("%d\n",n-1);
            for(int i=1;i<=n;i++) if(i!=pos) printf("%d ",i);
            puts("");
        }
    }
    return 0;
}
//
/// 
//01
//