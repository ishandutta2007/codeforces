#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

const int N = 5e4 + 5;
int a[N];

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%d", a + i);
        if(a[1] + a[2] <= a[n]) printf("1 2 %d\n", n);
        else printf("-1\n");
    }   
    return 0;
}