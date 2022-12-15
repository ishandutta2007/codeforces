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
    int T=1;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        int f=0;
        for(int i=2;i<=n;i++) if(a[i]==a[1]) f=1;
        if(!f){
            cout<<"1"<<endl;
            continue;
        }
        for(int i=2;i<=n;i++)
            if(a[i]!=a[1]){
                f=i;
                break;
            }
        cout<<f<<endl;
    }
    return 0;
}
//
/// 
//01
// 
//
//dp