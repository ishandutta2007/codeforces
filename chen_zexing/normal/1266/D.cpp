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
struct debt{
    int id;
    long long num;
};
struct ans{
    int x,y;
    long long w;
};
vector <debt> in,out;
vector <ans> a;
long long c[100005];
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            int x,y;
            long long z;
            scanf("%d%d%lld",&x,&y,&z);
            c[x]+=z,c[y]-=z;
        }
        for(int i=1;i<=n;i++){
            if(c[i]>0) out.push_back(debt{i,c[i]});
            if(c[i]<0) in.push_back(debt{i,-c[i]});
        }
        int x=0,y=0;
        while(y<in.size()&&x<out.size()){
            while(out[x].num==0&&x<out.size()) x++;
            while(in[y].num==0&&y<in.size()) y++;
            if(y>=in.size()||x>=out.size()) break;
            long long t=min(out[x].num,in[y].num);
            a.push_back(ans{out[x].id,in[y].id,t});
            out[x].num-=t,in[y].num-=t;
        }
        printf("%d\n",a.size());
        for(int i=0;i<a.size();i++) printf("%d %d %lld\n",a[i].x,a[i].y,a[i].w);
    }
    return 0;
}