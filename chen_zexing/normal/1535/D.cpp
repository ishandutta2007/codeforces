#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
char s[300005];
int tree[1200005];
void build(int node,int l,int r){
    if(l==r){
        tree[node]=(s[node]=='?'?2:1);
        return;
    }
    int mid=(l+r)>>1;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    if(s[node]=='?') tree[node]=tree[node*2]+tree[node*2+1];
    else tree[node]=tree[node*2+((s[node]-'0')^1)];
}
void modify(int node,int l,int r,int id,char c){
    if(node==id){
        s[node]=c;
        if(l==r) tree[node]=(s[node]=='?'?2:1);
        else{
            if(s[node]=='?') tree[node]=tree[node*2]+tree[node*2+1];
            else tree[node]=tree[node*2+((s[node]-'0')^1)];
        }
        return;
    }
    int mid=(l+r)>>1,temp=id;
    while(temp>node*2+1) temp/=2;
    if(temp==node*2) modify(node*2,l,mid,id,c);
    else modify(node*2+1,mid+1,r,id,c);
    if(s[node]=='?') tree[node]=tree[node*2]+tree[node*2+1];
    else tree[node]=tree[node*2+((s[node]-'0')^1)];
    //cout<<node<<" "<<tree[node]<<endl;
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,k,q;
        cin>>k;
        n=(1<<k)-1;
        scanf("%s",s+1);
        for(int i=1;i<=n/2;i++) swap(s[i],s[n-i+1]);
        build(1,1,(1<<(k-1)));
        cin>>q;
        while(q--){
            int t;
            char c='-';
            scanf("%d",&t);
            while(c!='1'&&c!='0'&&c!='?') scanf("%c",&c);
            modify(1,1,(1<<(k-1)),n-t+1,c);
            printf("%d\n",tree[1]);
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