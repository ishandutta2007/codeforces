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
long long tree[4000005][2],lz[4000005];
char s[1000005];
void pushdown(int node,int l,int r) {
    int mid = (l + r) >> 1;
    if (l == r) return;
    tree[node * 2][0] += lz[node],tree[node*2][1]+=lz[node];
    tree[node * 2 + 1][0] += lz[node],tree[node*2+1][1]+=lz[node];
    lz[node * 2] += lz[node], lz[node * 2 + 1] += lz[node], lz[node] = 0;
}
void update(int node,int l,int r,int L,int R,int v) {
    if (l >= L && r <= R) {
        tree[node][0] += v,tree[node][1]+=v;
        lz[node] += v;
        return;
    }
    pushdown(node, l, r);
    int mid = (l + r) >> 1;
    if (mid >= L) update(node * 2, l, mid, L, R, v);
    if (mid < R) update(node * 2 + 1, mid + 1, r, L, R, v);
    tree[node][0] = max(tree[node * 2][0], tree[node * 2 + 1][0]);
    tree[node][1]=min(tree[node*2][1],tree[node*2+1][1]);
}
long long query(int node,int l,int r,int L,int R,int f) {
    if (l >= L && r <= R) {
        return tree[node][f];
    }
    pushdown(node, l, r);
    int mid = (l + r) >> 1;
    if(f==0) {
        long long ans = 0;
        if (mid >= L) ans = max(ans, query(node * 2, l, mid, L, R,0));
        if (mid < R) ans = max(ans, query(node * 2 + 1, mid + 1, r, L, R,0));
        return ans;
    }
    else{
        long long ans=INT_MAX;
        if(mid>=L) ans=min(ans,query(node*2,l,mid,L,R,1));
        if(mid<R) ans=min(ans,query(node*2+1,mid+1,r,L,R,1));
        return ans;
    }
}
int main() {
    int n;
    scanf("%d\n",&n);
    int ck=0,pos=1;
    for(int i=1;i<=n;i++){
        char c;
        scanf("%c",&c);
        if(c=='R'){
            pos++;
            printf("%d ",ck);
        }
        else if(c=='L'){
            if(pos>1) pos--;
            printf("%d ",ck);
        }
        else{
            if(s[pos]=='('&&c==')') update(1,1,n,pos,n,-2);
            else if(s[pos]=='('&&c!='(') update(1,1,n,pos,n,-1);
            else if(s[pos]==')'&&c=='(') update(1,1,n,pos,n,2);
            else if(s[pos]==')'&&c!=')') update(1,1,n,pos,n,1);
            else if(c=='('&&s[pos]!='('&&s[pos]!=')') update(1,1,n,pos,n,1);
            else if(c==')'&&s[pos]!='('&&s[pos]!=')') update(1,1,n,pos,n,-1);
            if(query(1,1,n,1,n,1)<0||query(1,1,n,n,n,1)!=0) ck=-1;
            else ck=query(1,1,n,1,n,0);
            printf("%d ",ck);
            s[pos]=c;
        }
    }
    return 0;
}