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
using namespace std;
int main() {
    int T;
    cin>>T;
    while(T--){
        long long a,b,c,d;
        cin>>a>>b>>c>>d;
        if(b<a&&c<=d){
            puts("-1");
        }
        else if(b>=a){
            printf("%lld\n",b);
        }
        else printf("%lld\n",b+(a-b)/(c-d)*c+((a-b)%(c-d)>0)*c);
    }
    return 0;
}