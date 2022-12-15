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
using namespace std;
int tree[1300000],n,q;
void add(int x,int v){
    while(x<=1300000){
        tree[x]+=v;
        x+=x&-x;
    }
}
int query(int x){
    int ans=0;
    while(x){
        ans+=tree[x];
        x-=x&-x;
    }
    return ans;
}
int main() {
    int t;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d",&t),add(t,1);
    for(int i=1;i<=q;i++){
        scanf("%d",&t);
        if(t>0) add(t,1);
        else{
            t=-t;
            t--;
            int pos=0;
            for(int j=1<<19;j>=1;j/=2){
                if(tree[pos+j]<=t){
                    t-=tree[pos+j];
                    pos+=j;
                }
            }
            add(pos+1,-1);
        }
    }
    if(query(n)==0) puts("0");
    else{
        for(int i=1;i<=n;i++)
            if(tree[i]!=0){
                printf("%d\n",i);
                return 0;
            }
    }
    return 0;
}