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
using namespace std;
char s[200005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        long long a1,b1,a2,b2,k,a,b;
        scanf("%lld%lld%lld%lld%lld%lld%lld",&a1,&b1,&a2,&b2,&k,&b,&a);
        int f=0;
        for(int i=0;i<=k;i++){
            long long aa=a1+a*i,bb=b1+b*(k-i);
            long long t1=aa/b2+(aa%b2>0),t2=a2/bb+(a2%bb>0);
            //cout<<i<<" "<<aa<<" "<<bb<<" "<<a2<<" "<<b2<<" "<<t1<<" "<<t2<<endl;
            if(t2<=t1) f=1;
        }
        puts(f?"YES":"NO");
    }
    return 0;
}