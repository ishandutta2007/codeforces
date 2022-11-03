#include <cmath>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <ctime>

using namespace std;

bool ok(long long z) {
    for(int x=1;x<=z;++x) {
        if ((z-(x/2))%(x+1)==0) return true;
    }
    return false;
}

int mod=1000000007;
int arr[]={1,2,3,5,7,13,17,19,31,61,89,107,127,521,607,1279,2203,2281,3217,4253,4423,9689,9941,11213,19937,21701,23209,44497,86243,110503,132049,216091,756839,859433,1257787,1398269,2976221,3021377,6972593,13466917,20996011};

int mPow(int a,int x) {
    int ret=1;
    while(x) {
        if (x&1) ret=1LL*ret*a%mod;
        x>>=1; a=1LL*a*a%mod;
    }
    return ret;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    cout << (mPow(2,arr[n]-1)+mod-1)%mod << endl;
    return 0;
}