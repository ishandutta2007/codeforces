#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>

using namespace std;

int mPow(int a,int x,int mod) {
    int ret=1;
    while(x) {
        if (x&1) ret=(1LL*ret*a)%mod;
        x>>=1; a=(1LL*a*a)%mod;
    }
    return ret;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m;
    cin >> n >> m;
    cout << (mPow(3,n,m)+m-1)%m << endl;
    return 0;
}