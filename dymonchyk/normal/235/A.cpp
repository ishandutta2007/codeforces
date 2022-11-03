#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <queue>
#include <ctime>
#include <complex>
#include <map>
#include <set>
#pragma comment (linker,"/STACK:128000000")

using namespace std;

long long gcd(long long a,long long b) {return b==0 ? a : gcd(b,a%b);}
long long lcm(long long a,long long b) {return a/gcd(a,b)*b;}

long long go(int n) {
    long long ans=n;
    int t1=1,t2=1,t3=1;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            for(int t=1;t<=n;++t) {
                if (ans<lcm(i,lcm(j,t))) t1=i,t2=j,t3=t;
                ans=max(ans,lcm(i,lcm(j,t)));
//              if (ans==990&&n==12||n==30&&ans==21924) {
//                  cout << i << "  " << j << " " << t << endl;
//                  return ans;
//              }
            }
    cout << t1 << " " << t2 << "    " << t3 << endl;
    return ans;
}

long long solve(int n) {
    long long ans=n;
    for(long long i=1;i+2<=n;++i)
        ans=max(ans,lcm(i,lcm((i+1),(i+2))));
    for(long long i=1;i+3<=n;++i)
        ans=max(ans,lcm(i,lcm((i+3),(i+2))));
    for(long long i=1;i+3<=n;++i)
        ans=max(ans,lcm(i,lcm((i+1),(i+3))));
    return ans;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    cin >> n;
//  for(int i=1;i<=100;++i)
//      if (go(i)!=solve(i))
//          cout << go(i) << "  " << solve(i) << endl;
    cout << solve(n) << endl;
    return 0;
}