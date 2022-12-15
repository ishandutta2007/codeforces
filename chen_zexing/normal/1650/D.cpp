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
int a[2005],ans[2005],nxt[2005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=n;i>=1;i--){
            int pos=-1;
            for(int j=1;j<=i;j++) if(a[j]==i) pos=j;
            ans[i]=pos%i;
            for(int j=1;j<=pos;j++) nxt[j+i-pos]=a[j];
            for(int j=pos+1;j<=i;j++) nxt[j-pos]=a[j];
            for(int j=1;j<=i;j++) a[j]=nxt[j];
        }
        for(int i=1;i<=n;i++) printf("%d ",ans[i]);
        puts("");
    }
    return 0;
}
//unordered_map