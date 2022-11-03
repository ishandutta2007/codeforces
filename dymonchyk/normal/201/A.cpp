#include <cmath>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solve(int x) {
    if (x==3) return 5;
    for(int n=1;;n+=2) {
        int s=(n-1)/2;
        if (1+4*((s*s+1)/2+(s/2))>=x) return n;
    }
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    cout << solve(n) << endl;
//  for(int i=1;i<=100;++i)
//      cout << i << "  " << solve(i) << endl;
    return 0;
}