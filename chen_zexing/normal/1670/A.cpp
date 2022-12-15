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
        int n,pos=0,f=1;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),pos+=a[i]>0;
        for(int i=1;i<n-pos;i++) if(abs(a[i])<abs(a[i+1])) f=0;
        for(int i=n-pos+1;i<n;i++) if(abs(a[i])>abs(a[i+1])) f=0;
        puts(f?"YES":"NO");
    }
    return 0;
}
//unordered_map