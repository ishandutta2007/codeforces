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
        int a,b,c;
        cin>>a>>b>>c;
        int ans=min(b,c/2)*3;
        b-=ans/3;
        ans+=min(a,b/2)*3;
        cout<<ans<<endl;
    }
    return 0;
}