#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int n, ary[300100];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", &ary[i]);
    sort(ary, ary+n);
    long long ans = 0;
    for(int i = 0; i < n; ++i){
        ans += abs((i+1) - ary[i]);
    }
    cout << ans << endl;
    return 0;
}