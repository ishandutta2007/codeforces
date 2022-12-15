#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
int main() {
    int T=1;
    cin>>T;
    while(T--){
        long long p,a,b,c;
        cin>>p>>a>>b>>c;
        printf("%lld\n",min(min((a-p%a)%a,(b-p%b)%b),(c-p%c)%c));
    }
    return 0;
}