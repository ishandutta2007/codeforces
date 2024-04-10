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
        int ans=0;
        if(a>0) ans++,a--;
        if(b) ans++,b--;
        if(c) ans++,c--;
        if(a<b) swap(a,b);
        if(a<c) swap(a,c);
        if(a&&b) a--,b--,ans++;
        if(a&&c) a--,c--,ans++;
        if(b&&c) b--,c--,ans++;
        if(a&&b&&c) a--,b--,c--,ans++;
        cout<<ans<<endl;
    }
    return 0;
}