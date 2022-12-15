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
//#include <unordered_map>
#include <map>
#include <stack>
//#include <unordered_set>
#define hash hassh
using namespace std;
int main() {
    int T;
    cin>>T;
    while(T--){
        int x,y;
        cin>>x>>y;
        if(x<y) swap(x,y);
        int ans=y*2,t=x-y;
        if(t) ans+=t*2-1;
        printf("%d\n",ans);
    }
    return 0;
}