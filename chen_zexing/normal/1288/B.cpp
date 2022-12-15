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
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int a,b;
        cin>>a>>b;
        long long now=9,cnt=0;
        while(b>=now)
        {
            cnt++;
            now=now*10+9;
        }
        printf("%lld\n",cnt*a);
    }
    return 0;
}