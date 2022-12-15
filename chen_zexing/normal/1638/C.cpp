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
using namespace std;
int a[100005],f[100005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),f[i]=0;
        int mn=n+1,now=n,cnt=1,mx=n;
        while(now){
            while(a[now]!=mx) f[a[now]]=1,mn=min(mn,a[now--]);
            f[a[now]]=1,mn=min(mn,a[now]),now--;
            while(mx&&f[mx]) mx--;
            if(mx&&mx<mn) cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
//unordered_map