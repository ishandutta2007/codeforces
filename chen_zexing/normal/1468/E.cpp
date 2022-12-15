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
        int a[5];
        for(int i=1;i<=4;i++) cin>>a[i];
        sort(a+1,a+5);
        cout<<a[1]*a[3]<<endl;
    }
    return 0;
}