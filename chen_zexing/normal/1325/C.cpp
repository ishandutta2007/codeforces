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
struct edge{
    int ed,id;
};
vector <edge> v[100005];
int ans[100005];
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),v[x].push_back(edge{y,i}),v[y].push_back(edge{x,i});
        int f=0;
        for(int i=1;i<=n;i++){
            if(v[i].size()>2){
                f=1;
                for(int j=0;j<3;j++) ans[v[i][j].id]=j+1;
                break;
            }
        }
        if(f){
            int now=4;
            for(int i=1;i<n;i++){
                if(ans[i]) continue;
                ans[i]=now++;
            }
        }
        else for(int i=1;i<n;i++) ans[i]=i;
        for(int i=1;i<n;i++) printf("%d\n",ans[i]-1);
    }
    return 0;
}