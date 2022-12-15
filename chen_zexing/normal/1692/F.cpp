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
int cnt[10];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,f=0;
        cin>>n;
        memset(cnt,0,sizeof(cnt));
        for(int i=1,x;i<=n;i++) scanf("%d",&x),cnt[x%10]++;
        for(int i=0;i<10;i++)
            for(int j=0;j<10;j++)
                for(int k=0;k<10;k++){
                    cnt[i]--,cnt[j]--,cnt[k]--;
                    if(cnt[i]>=0&&cnt[j]>=0&&cnt[k]>=0){
                        if((i+j+k)%10==3) f=1;
                    }
                    cnt[i]++,cnt[j]++,cnt[k]++;
                }
        puts(f?"YES":"NO");
    }
    return 0;
}
//cf