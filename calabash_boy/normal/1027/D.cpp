


//
// Created by calabash_boy on 18-7-6.
//
#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB(x) push_back(x)
#define debug(x) cerr<<"[debug] "<<#x<<":"<<x<<endl;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
const int maxn = 2e5+100;
const int MOD = 1e9+7;
int n;
int c[maxn];
int d[maxn];
int a[maxn];
bool used[maxn];
void work(int x){
    used[x] = 1;
    x = a[x];
    d[x] --;
    while (d[x] == 0){
        used[x] = 1;
        x = a[x];
        d[x] --;
    }
}
int calc(int x){
//    used[x] = 1;
    int res = 0x3f3f3f3f;
    while (used[x] == false){
        used[x] = 1;
        res = min(res,c[x]);
        x = a[x];
    }
    return res;
}
int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",c+i);
    }
    for (int i=1;i<=n;i++){
        scanf("%d",a+i);
        d[a[i]] ++;
    }

    for (int i=1;i<=n;i++){
        if (d[i] == 0 && !used[i]){
            work(i);
        }
    }
    long long  ans = 0;
    for (int i=1;i<=n;i++){
        if (!used[i]){
            ans += calc(i);
        }
    }
    cout<<ans<<endl;
    return 0;
}