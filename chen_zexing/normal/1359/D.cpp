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
int a[100005];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int ans = INT_MIN, cnt = 0, mx = INT_MIN;
    for(int k=-30;k<=30;k++) {
        cnt=0;
        for (int i = 1; i <= n; i++) {
            if(a[i]>k)
            {
                mx=INT_MIN;
                cnt=0;
                continue;
            }
            mx = max(a[i], mx);
            cnt += a[i];
            ans = max(ans, cnt - mx);
            if (cnt < 0) {
                cnt = 0;
                mx = INT_MIN;
            }
        }
    }
    printf("%d\n", ans);
    return 0;

}