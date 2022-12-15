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
void solve(int x,int add){
    if(x==2){
        printf("%d %d\n",add+1,add+2);
        return;
    }
    solve(x-1,add+1);
    printf("%d %d\n",add+1,add+3);
}
int main() {
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        printf("2\n");
        solve(n,0);
    }
    return 0;
}