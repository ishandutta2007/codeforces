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
    int n,l,r;
    cin>>n>>l>>r;
    cout<<(1<<l)+(n-l-1)<<" "<<(1<<r)-1+(1<<(r-1))*(n-r)<<endl;
    return 0;
}