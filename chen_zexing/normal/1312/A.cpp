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
using namespace std;
int main() {
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        if(n%m==0) puts("YES");
        else puts("NO");
    }
    return 0;
}