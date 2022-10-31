#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
typedef long long ll;
ll a[maxn];
int n;
ll z;
bool check(int num){
    vector<ll> part1(0);
    vector<ll> part2(0);
    for (int i=0;i<num;i++){
        part1.push_back(a[i]);
    }
    for (int i=n-num;i<n;i++){
        part2.push_back(a[i]);
    }
    for (int i=0;i<num;i++){
        if (part2[i] - part1[i] <z)return false;
    }
    return true;
}
int main(){
    scanf("%d%lld",&n,&z);
    for (int i=0;i<n;i++){
        scanf("%lld",a+i);
    }
    sort(a,a+n);
    if (a[n-1] - a[0] < z) {
        puts("0");
        return 0;
    }
    int l = 1;
    int r = n/2;
    while (r-l > 1){
        int mid = l + r >> 1;
        if (check(mid)){
            l = mid;
        }else{
            r = mid;
        }
    }
    if (check(r)){
        cout<<r<<endl;
    }else{
        cout<<l<<endl;
    }
    return 0;
}