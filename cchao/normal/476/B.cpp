#include <bits/stdc++.h>
using namespace std;

double f(int dis, int n) {
    if(n == 0)
        return dis == 0 ? 1 : 0;
    return (f(dis + 1, n - 1) + f(dis - 1, n - 1)) / 2;
}

int main() {
    string a, b;
    cin >> a >> b;

    int target = 0;
    int now = 0;
    int n = 0;

    for(auto c: a)
        target += c == '+' ? 1 : -1;

    for(auto c: b)
        if(c == '?') n++;
        else now += c == '+' ? 1 : -1;

    printf("%.12f\n", f(target - now, n));

    return 0;
}