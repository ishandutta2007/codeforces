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
    int pos,type,id;
}a[400005];
bool cmp(node a,node b){
    return a.pos<b.pos||a.pos==b.pos&&a.type>b.type;
}
int ans,con[200005];
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n,x=0;
        cin>>n;
        for(int i=1,l,r;i<=n;i++){
            con[i]=0;
            scanf("%d%d",&l,&r);
            a[++x]=node{l,1,i};
            a[++x]=node{r,-1,i};
        }
        ans=0;
        sort(a+1,a+x+1,cmp);
        multiset <int> s;
        for(int i=1;i<=x;i++){
            if(a[i].type==1) s.insert(a[i].id);
            else s.erase(s.find(a[i].id));
            if(s.size()==0) ans++;
            if(s.size()==1&&a[i].type==-1&&a[i+1].type==1&&a[i].pos!=a[i+1].pos) con[*s.begin()]++;
            if(s.size()==1&&a[i].type==1&&a[i+1].type==-1) con[*s.begin()]--;
            //cout<<ans<<endl;
        }
        int mx=-1;
        for(int i=1;i<=n;i++) mx=max(mx,con[i]);
        cout<<ans+mx<<endl;
    }
    return 0;
}