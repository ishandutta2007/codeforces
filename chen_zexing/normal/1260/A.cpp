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
        int c,sum;
        cin>>c>>sum;
        int b=sum/c,t2=sum%c,t1=c-t2;
        printf("%lld\n",1LL*t1*b*b+1LL*t2*(b+1)*(b+1));
    }
    return 0;
}