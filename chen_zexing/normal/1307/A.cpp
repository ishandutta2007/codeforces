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
int a[105];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=2;i<=n;i++){
            if(d<i-1) break;
            if(d>(i-1)*a[i]){
                d-=(i-1)*a[i];
                a[1]+=a[i];
            }
            else{
                a[1]+=d/(i-1);
                break;
            }
        }
        cout<<a[1]<<endl;
    }
    return 0;
}
//
/// 
//01
// 
//
//dp