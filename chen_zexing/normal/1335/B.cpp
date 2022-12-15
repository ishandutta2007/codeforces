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
    int T = 1;
    cin >> T;
    while (T--) {
        int n,a,b;
        cin>>n>>a>>b;
        for(int i=0;i<n;i++) printf("%c",'a'+i%b);
        puts("");
    }
    return 0;
}