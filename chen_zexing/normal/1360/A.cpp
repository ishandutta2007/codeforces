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
        int a,b;
        cin>>a>>b;
        cout<<min(max(a,b*2)*max(a,b*2),max(b,a*2)*max(b,a*2))<<endl;
    }
    return 0;
}