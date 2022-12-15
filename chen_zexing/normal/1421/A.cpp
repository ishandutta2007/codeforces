#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
using namespace std;
char s[205][205];
int main() {
    int T;
    cin>>T;
    while(T--){
        long long a,b;
        cin>>a>>b;
        printf("%lld\n",(b|a)&(a^b));
    }
    return 0;
}