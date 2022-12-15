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
    int T;
    cin>>T;
    while(T--){
        int a,b;
        cin>>a>>b;
        if((a+b)%3||min(a,b)*2<max(a,b)) puts("NO");
        else puts("YES");
    }
    return 0;
}