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
    int n,m;
    cin >> n >> m;
    n=min(n,m); m=min(n,m);
    cout << n+1 << endl;
    for(int i=0;i<=n;++i)
        cout << i << " " << n-i << endl;
    return 0;
}