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
int sa[100005],ea[100005],sb[100005],eb[100005];
int b[400005];
struct oper{
    int type,t,id;
};
vector <oper> v[400005];
int tr[400005],n,tr2[400005];
void add(int x,int v){
    while(x<=n*4) tr[x]+=v,x+=x&-x;
}
int query(int x){
    int ans=0;
    while(x) ans+=tr[x],x-=x&-x;
    return ans;
}
void add2(int x,int v){
    while(x<=n*4) tr2[x]+=v,x+=x&-x;
}
int query2(int x){
    int ans=0;
    while(x) ans+=tr2[x],x-=x&-x;
    return ans;
}
int f[100005];
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        cin>>n;
        int x=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d%d",&sa[i],&ea[i],&sb[i],&eb[i]);
            b[++x]=sa[i],b[++x]=ea[i],b[++x]=sb[i],b[++x]=eb[i];
        }
        sort(b+1,b+x+1);
        int t=0;
        for(int i=1;i<=n;i++){
            sa[i]=lower_bound(b+1,b+x+1,sa[i])-b;
            ea[i]=lower_bound(b+1,b+x+1,ea[i])-b;
            sb[i]=lower_bound(b+1,b+x+1,sb[i])-b;
            eb[i]=lower_bound(b+1,b+x+1,eb[i])-b;
            v[sa[i]].push_back(oper{1,sa[i],i});
            v[ea[i]].push_back(oper{-1,ea[i],i});
        }
        int fl=1;
        int cnt=0;
        for(int i=1;i<=n*4;i++){
            for(int j=0;j<v[i].size();j++){
                if(v[i][j].type==1){
                    int id=v[i][j].id;
                    int t1=query(sb[id]-1),t2=cnt-query2(eb[id]);
                    if(t1+t2!=cnt) fl=0;
                }
            }
            for(int j=0;j<v[i].size();j++){
                if(v[i][j].type==-1){
                    int id=v[i][j].id;
                    add(eb[id],1),add2(sb[id],1);
                    cnt++;
                }
            }
        }
        cnt=0;
        memset(tr,0,sizeof(tr));
        memset(tr2,0,sizeof(tr2));
        for(int i=n*4;i>=1;i--){
            for(int j=0;j<v[i].size();j++){
                if(v[i][j].type==-1){
                    int id=v[i][j].id;
                    int t1=query(sb[id]-1),t2=cnt-query2(eb[id]);
                    if(t1+t2!=cnt) fl=0;
                }
            }
            for(int j=0;j<v[i].size();j++){
                if(v[i][j].type==1){
                    int id=v[i][j].id;
                    add(eb[id],1),add2(sb[id],1);
                    cnt++;
                }
            }
        }
        for(int i=1;i<=n*4;i++) v[i].clear();
        for(int i=1;i<=n;i++) swap(sa[i],sb[i]),swap(ea[i],eb[i]);
        memset(tr,0,sizeof(tr));
        memset(tr2,0,sizeof(tr2));
        for(int i=1;i<=n;i++){
            v[sa[i]].push_back(oper{1,sa[i],i});
            v[ea[i]].push_back(oper{-1,ea[i],i});
        }
        cnt=0;
        for(int i=1;i<=n*4;i++){
            for(int j=0;j<v[i].size();j++){
                if(v[i][j].type==1){
                    int id=v[i][j].id;
                    int t1=query(sb[id]-1),t2=cnt-query2(eb[id]);
                    if(t1+t2!=cnt) fl=0;
                }
            }
            for(int j=0;j<v[i].size();j++){
                if(v[i][j].type==-1){
                    int id=v[i][j].id;
                    add(eb[id],1),add2(sb[id],1);
                    cnt++;
                }
            }
        }
        cnt=0;
        memset(tr,0,sizeof(tr));
        memset(tr2,0,sizeof(tr2));
        for(int i=n*4;i>=1;i--){
            for(int j=0;j<v[i].size();j++){
                if(v[i][j].type==-1){
                    int id=v[i][j].id;
                    int t1=query(sb[id]-1),t2=cnt-query2(eb[id]);
                    if(t1+t2!=cnt) fl=0;
                }
            }
            for(int j=0;j<v[i].size();j++){
                if(v[i][j].type==1){
                    int id=v[i][j].id;
                    add(eb[id],1),add2(sb[id],1);
                    cnt++;
                }
            }
        }
        if(fl) puts("YES");
        else puts("NO");
    }
    return 0;
}