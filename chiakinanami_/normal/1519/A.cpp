#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
ll r, b, d;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%lld %lld %lld", &r, &b, &d);
        if(r>b) swap(r, b);
        printf("%s\n", r*(d+1) < b ? "NO" : "YES");
    }
}