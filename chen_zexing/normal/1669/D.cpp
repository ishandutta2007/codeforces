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
char s[200005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n;
        cin>>n;
        scanf("%s",s+1);
        int cb=0,cr=0,f=1;
        for(int i=1;i<=n+1;i++){
            if(i==n+1||s[i]=='W'){
                if(cb&&!cr||cr&&!cb) f=0;
                cb=0,cr=0;
            }
            else if(s[i]=='R') cr++;
            else cb++;
        }
        puts(f?"YES":"NO");
    }
    return 0;
}
//unordered_map