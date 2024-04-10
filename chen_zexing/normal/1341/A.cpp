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
        int n,a,b,c,d;
        cin>>n>>a>>b>>c>>d;
        int l1=(a-b)*n,r1=(a+b)*n,l2=c-d,r2=c+d;
        if(r1<l2||r2<l1) puts("No");
        else puts("Yes");
    }
    return 0;
}