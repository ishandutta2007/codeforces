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
struct node{
    int x,y;
};
vector <node> v[3];
int ans[105][105];
int main() {
    int T=1;
    //cin>>T;
    while(T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                v[(i+j)%2+1].push_back(node{i,j});
        int tot=n*n,c[3]={};
        while(tot--){
            int t;
            scanf("%d",&t);
            if(t==3) {
                if (c[1] < v[1].size()) printf("%d %d %d\n",1,v[1][c[1]].x,v[1][c[1]].y),c[1]++;
                else printf("%d %d %d\n",2,v[2][c[2]].x,v[2][c[2]].y),c[2]++;
            }
            else if(t==2){
                if(c[1]<v[1].size()) printf("%d %d %d\n",1,v[1][c[1]].x,v[1][c[1]].y),c[1]++;
                else printf("%d %d %d\n",3,v[2][c[2]].x,v[2][c[2]].y),c[2]++;
            }
            else{
                if (c[2] < v[2].size()) printf("%d %d %d\n",2,v[2][c[2]].x,v[2][c[2]].y),c[2]++;
                else printf("%d %d %d\n",3,v[1][c[1]].x,v[1][c[1]].y),c[1]++;
            }
            fflush(stdout);
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