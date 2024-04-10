#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;
int n, m, k;
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        cin>>n >> m >> k;
        bool have = 0;
        while (m --) {
            int x;
            cin>>x;
            if (x == n) have = 1;
        }
        while (k --) {
            int x;
            cin>>x;
        }
        if (have) printf("YES\n");else printf("NO\n");
    }
}