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
        int a,b,c;
        cin>>a>>b>>c;
        printf("%lld\n",max(0LL,2LL*(max(a,max(b,c))-min(a,min(b,c))-2)));
    }
    return 0;
}