#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
#include <assert.h>
#include <random>
using namespace std;
//
struct node{
    int x1,y1,x2,y2;
};
int main() {
    int T = 1, kase = 0;
    //cin >> T;
    while (T--) {
        int x[4],y[4],ox[4],oy[4];
        for(int i=1;i<=3;i++) cin>>x[i]>>y[i],ox[i]=x[i],oy[i]=y[i];
        sort(x+1,x+4),sort(y+1,y+4);
        int xx=x[2],yy=y[2];
        vector <node> ans;
        for(int i=1;i<=3;i++){
            if(ox[i]!=xx) ans.push_back(node{ox[i],oy[i],xx,oy[i]});
            if(oy[i]!=yy) ans.push_back(node{xx,oy[i],xx,yy});
        }
        printf("%d\n",ans.size());
        for(auto t:ans) printf("%d %d %d %d\n",t.x1,t.y1,t.x2,t.y2);
    }
    return 0;
}
//unordered_map