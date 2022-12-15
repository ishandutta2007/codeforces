#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#define hash hassh
using namespace std;
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,f=0;
        cin>>n;
        if(n==1){
            puts("Bob");
            continue;
        }
        int temp=n;
        while(temp%2==0){
            temp/=2,f++;
        }
        if(temp!=1){
            puts(n%2?"Bob":"Alice");
        }
        else{
            puts(f%2?"Bob":"Alice");
        }
    }
    return 0;
}
//
/// 
//01
// 
//
//dp