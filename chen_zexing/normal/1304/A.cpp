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
#define hash hassh
using namespace std;
int main() {
    int T;
    cin>>T;
    while(T--) {
        int x,y,a,b;
        cin>>x>>y>>a>>b;
        if((y-x)%(a+b)==0){
            printf("%d\n",(y-x)/(a+b));
        }
        else puts("-1");
    }
    return 0;
}