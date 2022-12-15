#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <stdlib.h>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    int mx=0;
    for(int i=3;i<=n;i++) mx+=(i-1)/2;
    if(m>mx) puts("-1");
    else{
        vector <int> ans;
        int rest=mx-m;
        int now=n,v;
        while(rest){
            int r=(now-1)/2;
            v=now;
            while(r&&rest){
                r--;
                rest--;
                v+=2;
            }
            if(rest) srand(rand()),v=1e9-(n-now)*n*10;
            ans.push_back(v);
            now--;
        }
        for(int i=1;i<=now;i++) ans.push_back(i);
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
    }
    return 0;
}