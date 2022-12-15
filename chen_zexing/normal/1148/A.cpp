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
    //cin>>T;
    while(T--){
        long long a,b,c;
        cin>>a>>b>>c;
        long long ans=2*c;
        if(a!=b) ans+=min(a,b)*2+1;
        else ans+=a*2;
        cout<<ans<<endl;
    }
    return 0;
}