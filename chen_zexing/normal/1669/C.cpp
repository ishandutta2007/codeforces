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
int a[55];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,f=1;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++){
            if(i%2&&a[i]%2!=a[1]%2||i%2==0&&a[i]%2!=a[2]%2) f=0;
        }
        puts(f?"YES":"NO");
    }
    return 0;
}
//unordered_map