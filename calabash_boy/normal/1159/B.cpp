#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 100;
int n;
int a[maxn];
int rk[maxn];
bool check(long long k){
    int min_idx = INT_MAX;
    int max_idx = -1;
    for (int i=0;i<n;i++){
        int pos = rk[i];
        if (min_idx <= pos){
            long long temp = k * (pos - min_idx);
            if (temp > a[pos])return false;
        }
        if (max_idx >= pos){
            long long temp = k * (max_idx - pos);
            if (temp > a[pos])return false;
        }
        max_idx = max(max_idx,pos);
        min_idx = min(min_idx,pos);
    }
    return true;
}
int main(){
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i];
        rk[i] = i;
    }
    sort(rk,rk+ n,[](int x,int y){
        return a[x] > a[y];
    });
    long long l = 0;
    long long r = INT_MAX;
    while (r-l > 1){
        long long mid = l + r >> 1;
        if (check(mid)){
            l = mid;
        }else{
            r = mid;
        }
    }
    if (check(r))cout<<r<<endl;
    else cout<<l<<endl;
    return 0;
}