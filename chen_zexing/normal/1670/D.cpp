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
    //cin >> T;
    while (T--) {
        int n,now=0,ans=0;
        //cin>>n;
        for(int i=1;ans<=38730;i++){
            now+=(i-1)*4,ans++;
            a[(i-1)*3+1]=now;
            now+=(2*i-1)*2,ans++;
            a[(i-1)*3+2]=now;
            now+=4*i,ans++;
            a[i*3]=now;
        }
        int t;
        cin>>t;
        while(t--){
            scanf("%d",&n);
            int pos=lower_bound(a+1,a+38731,n)-a;
            printf("%d\n",pos);
        }
    }
    return 0;
}
//unordered_map