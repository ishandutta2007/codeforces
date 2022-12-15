#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string.h>
#include <limits.h>
#include <map>
#include <string>
#include <bitset>
#include <vector>
using namespace std;
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        long long l,r;
        cin>>l>>r;
        if(l*2<=r) printf("%lld %lld\n",l,l*2);
        else printf("-1 -1\n");
    }
    return 0;
}