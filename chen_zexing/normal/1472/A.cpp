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
        int w,h,n;
        int c1=1,c2=1;
        cin>>w>>h>>n;
        while(w%2==0) w/=2,c1*=2;
        while(h%2==0) h/=2,c2*=2;
        if(c1*c2>=n) puts("YES");
        else puts("NO");
    }
    return 0;
}