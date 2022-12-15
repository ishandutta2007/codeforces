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
int gcd(int a,int b){
    return a%b==0?b:gcd(b,a%b);
}
int main() {
    int T;
    cin>>T;
    while(T--){
        int a,b;
        cin>>a>>b;
        if(gcd(a,b)==1) puts("Finite");
        else puts("Infinite");
    }
    return 0;
}