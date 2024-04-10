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
using namespace std;
int main() {
    int T = 1;
    cin >> T;
    while(T--) {
        int a,b,c;
        cin>>a>>b>>c;
        if((b*2-a)%c==0&&b*2-a>0) puts("YES");
        else if((a+c)%2==0&&(a+c)/2%b==0) puts("YES");
        else if((b*2-c)%a==0&&b*2-c>0) puts("YES");
        else puts("NO");
    }
    return 0;
}