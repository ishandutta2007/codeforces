#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <algorithm>
#include <map>
#include <cmath>
#include <unordered_map>
using namespace std;
int a[50005];
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        int f = 0;
        for (int i = 2; i <= n; i++) if (a[i] >= a[i - 1]) f = 1;
        if (f) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}