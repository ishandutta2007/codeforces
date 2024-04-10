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
int a[100005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,cnt=0,now=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++){
            if(a[i]==0||i==n){
                if(a[i]) now++;
                if(now) cnt++;
                now=0;
            }
            else now++;
        }
        printf("%d\n",min(cnt,2));
    }
    return 0;
}
//cf