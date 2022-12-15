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
int main() {
    int T = 1;
    cin >> T;
    while(T--){
        int a,b,c,mx=0;
        scanf("%d%d%d",&a,&b,&c);
        mx=max(max(a,b),c);
        int cnt=0;
        if(a==mx) cnt++;
        if(b==mx) cnt++;
        if(c==mx) cnt++;
        if(a<mx) printf("%d ",mx-a+1);
        else if(cnt>1) printf("1 ");
        else printf("0 ");
        if(b<mx) printf("%d ",mx-b+1);
        else if(cnt>1) printf("1 ");
        else printf("0 ");
        if(c<mx) printf("%d ",mx-c+1);
        else if(cnt>1) printf("1 ");
        else printf("0 ");
        puts("");
    }
    return 0;
}
//
/// 
//01
//