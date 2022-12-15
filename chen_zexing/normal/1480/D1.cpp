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
int a[100005];
vector <int> v[100005];
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int x=0,y=0,n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) {
            v[a[i]].push_back(i);
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            int ok=2;
            for(int j=0;j<v[i].size();j++){
                if(j) ok+=v[i][j]-v[i][j-1]-1;
                if(ok>2) ok=2;
                if(ok) ans++,ok--;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}