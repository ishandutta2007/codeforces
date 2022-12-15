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
        int n;
        cin>>n;
        if(n==1){
            puts("0");
            continue;
        }
        if(n==2){
            puts("1");
            continue;
        }
        if(n%2==0){
            puts("2");
            continue;
        }
        if(n==3){
            puts("2");
            continue;
        }
        if(n%2){
            puts("3");
            continue;
        }
    }
    return 0;
}