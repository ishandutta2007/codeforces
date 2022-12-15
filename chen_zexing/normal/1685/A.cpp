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
int a[100005],ans[100005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        if(n%2) puts("NO");
        else{
            int x=0;
            for(int i=1;i<=n/2;i++) ans[++x]=a[i],ans[++x]=a[i+n/2];
            ans[n+1]=a[1];
            int f=1;
            for(int i=2;i<=n;i++){
                if(!(ans[i]>ans[i-1]&&ans[i]>ans[i+1]||ans[i]<ans[i-1]&&ans[i]<ans[i+1])) f=0;
            }
            if(!f){
                puts("NO");
                continue;
            }
            puts("YES");
            for(int i=1;i<=n;i++) printf("%d ",ans[i]);
            puts("");
        }
    }
    return 0;
}