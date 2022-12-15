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
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        cin>>n;
        vector <int> v[2];
        for(int i=1,x;i<=n;i++) scanf("%d",&x),v[x%2].push_back(x);
        int ans=(v[1].size()+n-1)*v[0].size()/2;
        for(int i=0;i<v[1].size();i++)
            for(int j=i+1;j<v[1].size();j++)
                if(gcd(v[1][i],v[1][j])>1) ans++;
        cout<<ans<<endl;
    }
    return 0;
}
//
/// 
//01
// 
//
//dp