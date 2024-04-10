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
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int a,b;
        cin>>a>>b;
        int ans=b-a;
        for(int i=a;i<=b;i++) ans=min(ans,i-a+(i|b)-b+1);
        for(int i=b;i<=b*3;i++) ans=min(ans,i-b+(a|i)-i+1);
        printf("%d\n",ans);
    }
    return 0;
}
//unordered_map