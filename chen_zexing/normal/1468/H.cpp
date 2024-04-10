#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
int a[200005],f[200005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,m,k;
        cin>>n>>k>>m;
        int tot=n;
        for(int i=1;i<=n;i++) f[i]=0;
        for(int i=1;i<=m;i++) scanf("%d",&a[i]),f[a[i]]=1,tot--;
        int fl=0,now=0;
        for(int i=1;i<=n;i++){
            if(f[i]){
                if(now>=k/2&&tot-now>=k/2) fl=1;
            }
            else now++;
        }
        if(fl&&(n-m)%(k-1)==0) puts("YES");
        else puts("NO");
    }
    return 0;
}