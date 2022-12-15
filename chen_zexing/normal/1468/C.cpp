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
struct cust{
    int id,cost;
    friend bool operator <(cust a,cust b){
        return a.cost>b.cost||a.cost==b.cost&&a.id<b.id;
    }
};
set <cust> s;
int f[500005];
cust cus[500005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int q,t,c,x=0,cur=1;
        cin>>q;
        for(int i=1;i<=q;i++){
            scanf("%d",&t);
            if(t==1){
                scanf("%d",&c);
                s.insert(cust{++x,c});
                cus[x]=cust{x,c};
            }
            else if(t==2){
                while(f[cur]) cur++;
                printf("%d ",cus[cur].id);
                s.erase(s.find(cus[cur++]));
            }
            else{
                printf("%d ",(*s.begin()).id);
                f[(*s.begin()).id]=1;
                s.erase(s.begin());
            }
        }
    }
    return 0;
}