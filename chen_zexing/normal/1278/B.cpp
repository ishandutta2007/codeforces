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
        int a,b;
        cin>>a>>b;
        int t=abs(a-b);
        long long now=0,p=1;
        while(!(now>=t&&(now-t)%2==0)){
            now+=p;
            p++;
        }
        p--;
        cout<<p<<endl;
    }
    return 0;
}