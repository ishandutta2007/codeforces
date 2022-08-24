#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <bits/stdc++.h>
#include <math.h>
#include <fstream>
using namespace std;
long long f[1000000];
long long n;
long long func(long long i){
    return i & (i + 1);
}
long long res(long long p){
    long long ans = 0;
    while (func(p) >= 0 && p >= 0){
        ans += f[p];
        p = func(p) - 1;
    }
    return ans;
}
long long modify(long long s){
    while (s < n){
        f[s] += 1;
        s = s | (s + 1);
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    long long k;
    cin >> n >> k;
    for (int i=0;i<n;i++){
        f[i] = 0;
    }
    if (k > n/2){
        k = n - k;
    }
    long long answer = 1;
    long long point = 0;
    for (int i=0;i<n;i++){
        long long new_point = (point + k) % n;
        long long result;
        if (point < new_point){
            result = res(new_point - 1) - res(point);
        }
        else{
            result = res(new_point - 1) + res(n - 1) - res(point);
        }
        answer += result + 1;
        modify(new_point);
        modify(point);
        point = new_point;
        cout << answer << " ";
    }
    return 0;
}