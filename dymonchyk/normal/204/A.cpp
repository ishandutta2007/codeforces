#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <ctime>
#include <memory.h>
#pragma comment("/:STACK:64000000",linker)

using namespace std;

long long get(long long n) {
    if (n<10) return n;
    long long ret=0,step10=1,num=0;
    vector <int> v;
    while(n) {
        v.push_back(n%10);
        n/=10;
    }
    reverse(v.begin(),v.end());
    for(int i=1;i<v.size();++i) {
        ret+=9*step10; if (i>1) step10*=10;
    }
    ret+=(v[0]-1)*step10;
    for(int i=1;i+1<v.size();++i)
        num=num*10+v[i];
    ++num;
    ret+=num;
    if (v[0]>v.back()&&num) --ret;
    return ret;
}

void check(int n = 10000) {
    int cnt=0;
    for(int i=1;i<=n;++i) {
        vector <int> v;
        int k=i;
        while(k) {
            v.push_back(k%10);
            k/=10;
        }
        if (v[0]==v.back()) ++cnt;
        if (cnt!=get(i)) {
            cout << i << endl;
            return;
        }
    }
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    long long l,r;
    cin >> l >> r;
    cout << get(r)-get(l-1) << endl;
//  check();
    return 0;
}