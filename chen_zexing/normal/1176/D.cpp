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
int f[3000005],cnt,bk[3000005],prime[200005];
int b[400005];
multiset <int> s;
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        for(int i=2;i<=3000000;i++)
            if(!f[i]){
                bk[i]=++cnt,prime[cnt]=i;
                for(int j=i*2;j<=3000000;j+=i) f[j]=1;
            }
        int n;
        cin>>n;
        for(int i=1;i<=n*2;i++) scanf("%d",&b[i]),s.insert(b[i]);
        for(int i=1;i<=n;i++){
            auto it=s.end();
            --it;
            int temp=*it;
            s.erase(it);
            if(f[temp]){
                printf("%d ",temp);
                for(int j=2;j*j<=temp;j++)
                    if(temp%j==0){
                        s.erase(s.find(temp/j));
                        break;
                    }
            }
            else{
                printf("%d ",bk[temp]);
                s.erase(s.find(bk[temp]));
            }
        }
    }
    return 0;
}
//
/// 
//01
//