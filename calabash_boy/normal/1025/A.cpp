//
// Created by calabash_boy on 18-7-6.
//
#include<bits/stdc++.h>
#define F first
#define S second
#define PB(x) push_back(x)
#define debug(x) cout<<"[debug] "<<#x<<":"<<x<<endl;
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
const int maxn = -1;
const int MOD = -1;
LL pow_mod(LL x,LL y){
    LL ret = 1;
    for (;y;y>>=1){if (y&1) ret = ret*x%MOD;x = x*x%MOD;}
    return ret;
}

int n;
char s[100005];


int a[128];
signed main() {
    cin >> n >> s;
    if(n == 1) {
        puts("Yes");
        return 0;
    }
    for(int i=0;i<n;i++)
        a[s[i]-'a']++;
    for(int i=0;i<26;i++)
        if(a[i]>=2) {puts("Yes");return 0;}
    puts("No");
    return 0;
}