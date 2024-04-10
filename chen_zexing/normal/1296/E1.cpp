#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <map>
using namespace std;
char s[205];
int ans[205];
vector <int> a,b;
int main() {
    int n, f = 1;
    cin >> n;
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) {
        if (a.size() == 0 || s[i] >= s[a[a.size() - 1]]) a.push_back(i);
        else if (b.size() == 0 || s[i] >= s[b[b.size() - 1]]) b.push_back(i);
        else {
            f = 0;
            break;
        }
    }
    for (int i = 0; i < a.size(); i++) ans[a[i]] = 1;
    for (int i = 0; i < b.size(); i++) ans[b[i]] = 0;
    if (f) {
        printf("YES\n");
        for (int i = 1; i <= n; i++) printf("%d", ans[i]);
    }
    else printf("NO\n");
    return 0;
}