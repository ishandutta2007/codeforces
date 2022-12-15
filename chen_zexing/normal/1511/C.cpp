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
int a[600005],fst[55];
vector <int> v;
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n,q;
        cin>>n>>q;
        for(int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
            if(!fst[a[i]]) fst[a[i]]=i;
        }
        while(q--) {
            int t;
            scanf("%d",&t);
            for(int i=1;i<=50;i++) if(fst[i]<fst[t]) fst[i]++;
            printf("%d ",fst[t]);
            fst[t]=1;
        }
    }
    return 0;
}
//
/// 
//01
// 
//
//dp