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
int a[200005];
map <int,int> lst,fst;
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,q;
        scanf("%d%d",&n,&q);
        lst.clear(),fst.clear();
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),lst[a[i]]=i;
        for(int i=n;i>=1;i--) fst[a[i]]=i;
        for(int i=1,x,y;i<=q;i++){
            scanf("%d%d",&x,&y);
            puts(fst[x]&&lst[y]&&fst[x]<=lst[y]?"YES":"NO");
        }
    }
    return 0;
}
//unordered_map