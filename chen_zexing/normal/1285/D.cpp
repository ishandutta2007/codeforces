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
int a[100005],cnt;
struct node{
    int v,son[2],h;
}tr[3000005];
void insert(int x){
    int now=0;
    for(int i=29;i>=0;i--){
        int temp=((1<<i)&x)>0;
        if(tr[now].son[temp]) now=tr[now].son[temp];
        else tr[now].son[temp]=++cnt,now=tr[now].son[temp],tr[now].h=i;
    }
}
int solve(int x){
    if(!tr[x].son[0]&&!tr[x].son[1]) return 0;
    if(!tr[x].son[0]) return solve(tr[x].son[1]);
    if(!tr[x].son[1]) return solve(tr[x].son[0]);
    return min((1<<(tr[tr[x].son[0]].h))+solve(tr[x].son[1]),(1<<(tr[tr[x].son[1]].h))+solve(tr[x].son[0]));
}
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),insert(a[i]);
        cout<<solve(0)<<endl;
    }
    return 0;
}