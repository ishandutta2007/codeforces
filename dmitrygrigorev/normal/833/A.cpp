#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <string>
#include <map>
#include <unordered_set>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <fstream>
#include <bitset>
#include <time.h>
#include <queue>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int n, x, y, f, s;
    scanf("%d", &n);
    unordered_set<long long> mp;
    long long K = 1e9 + 7;
    for (int i=1; i <= 1000; i++){
        for (int j=1; j*j*i <= K; j++){
            f = i * j * j;
            s = i * i * j;
            if (f > s) swap(f, s);
            mp.insert((long long) s * K + f);
        }
    }
    for (int i=0; i < n; i++){
        scanf("%d %d", &x, &y);
        if (x > y) swap(x, y);
        if (mp.count((long long) y * K + x)) printf("%s \n", "Yes");
        else printf("%s \n", "No");
    }
    return 0;
}