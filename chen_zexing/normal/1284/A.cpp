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
string a[25],b[25];
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<m;i++) cin>>b[i];
        int q;
        cin>>q;
        while(q--){
            int t;
            scanf("%d",&t);
            cout<<a[(t-1)%n]<<b[(t-1)%m]<<endl;
        }
    }
    return 0;
}