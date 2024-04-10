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
    int n,a[32],h[32],ans=0;
    cin >> n;
    for(int i=0;i<n;++i)
        cin >> h[i] >> a[i];
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            if (h[i]==a[j]) ++ans;
    cout << ans << endl;
    return 0;
}