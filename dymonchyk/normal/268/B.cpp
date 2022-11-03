#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <ctime>

using namespace std;

int main() {
//  freopen("input.txt","r", stdin);
//  freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    long long ans=0;
    for(int i=0;i<n;++i) {
        ans+=(n-i)*(i+1)-i;
    }
    cout << ans << endl;
    return 0;
}