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

int mod=1000000007;

int mPow(int a,int x,int mod) {
    int ret=1;
    while(x) {
        if (x&1) ret=(1LL*ret*a)%mod;
        x>>=1; a=(1LL*a*a)%mod;
    }
    return ret;
}

int rev(int x) {
    return mPow(x,mod-2,mod);
}

int inv[2002]={0};

int getC(int n,int k) {
    if (n<0||k<0||k>n) return 0;
    int ret=1;
    for(int i=0;i<k;++i) {
        ret=(1LL*ret*(n-i))%mod;
        ret=(1LL*ret*inv[i+1])%mod;
    }
    return ret;
}

int C[2002];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,k,arr[2002]={0},ans[2002]={0};
    cin >> n >> k; --k;
    for(int i=0;i<n;++i) {
        cin >> arr[i];
        ans[i]=arr[i];
        if (k>=0) arr[i]=0;
    }
    if (k>=0) {
        for(int i=1;i<=2000;++i)
            inv[i]=rev(i);
        for(int i=0;i<=2000;++i)
            C[i]=getC(k+i,i);
        for(int i=0;i<n;++i) {
            for(int j=i;j<n;++j) {
                arr[j]+=1LL*ans[i]*C[j-i]%mod;
                if (arr[j]>=mod) arr[j]-=mod;
            }
        }
    }
    for(int i=0;i<n;++i) {
        if (i) cout << " ";
        cout << arr[i];
    }
    cout << endl;
    return 0;
}