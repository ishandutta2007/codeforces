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
        int a,b,c;
        cin>>a>>b>>c;
        int s=a+b+c;
        int t=s/9;
        if(s%9){
            puts("No");
            continue;
        }
        if(min(a,min(b,c))<t) puts("No");
        else puts("Yes");
    }
    return 0;
}