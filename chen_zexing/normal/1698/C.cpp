#pragma GCC optimize(3)
#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
#include <assert.h>
#include <random>
#include <bitset>
using namespace std;
long long a[200005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,cnt=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        vector <long long> v;
        for(int i=1;i<=n;i++){
            if(a[i]>0||a[i]<0) v.push_back(a[i]);
            else cnt++;
        }
        if(v.size()>=10){
            puts("NO");
            continue;
        }
        if(cnt) v.push_back(0);
        int fl=1;
        for(int i=0;i<v.size();i++)
            for(int j=i+1;j<v.size();j++)
                for(int k=j+1;k<v.size();k++){
                    int f=0;
                    for(auto t:v) if(t==v[i]+v[j]+v[k]) f=1;
                    if(!f) fl=0;
                }
        puts(fl?"YES":"NO");
    }
    return 0;
}
//cf