#include <stdio.h>
#include <iostream>
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
    while(T--) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a<b) swap(a,b);
        if(a<c) swap(a,c);
        if(a<=b+c) printf("%d\n",(a+b+c)/2);
        else printf("%d\n",b+c);
    }
    return 0;
}