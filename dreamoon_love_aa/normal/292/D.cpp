#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
#define SIZE 501
int record[2][SIZE],an[20001],C,cc,ex[20001],ey[20001];
int init(int d[][SIZE],int n){for(int i=1;i<=n;i++)d[0][i]=record[0][i],d[1][i]=record[1][i];}
int find(int d[],int x){return x!=d[x]?(d[x]=find(d,d[x])):x;}
bool uu(int d[][SIZE],int x,int y){
    x=find(d[0],x);
    y=find(d[0],y);
    if(x==y)return 0;
    if(d[1][x]<d[1][y]){d[0][x]=y;d[1][y]+=d[1][x];}
    else{d[0][y]=x;d[1][x]+=d[1][y];}
    return 1;
}
struct data{
    int y,No;
    data(int _y=0,int _No=0){y=_y;No=_No;}
    bool operator<(const data& b)const{return y>b.y;}
};
vector<data>e[20001];
int main(){
    int i,j,k,n,m;
    int d[2][SIZE];
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)scanf("%d%d",&ex[i],&ey[i]);
    scanf("%d",&k);
    for(i=1;i<=k;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        e[l].pb(data(r,i));
    }
    int st=m;
    for(i=1;i<=n;i++)record[0][i]=i,record[1][i]=1;
    cc=n;
    for(i=1;i<=m;i++){
        sort(e[i].begin(),e[i].end());
        int now=st;
        init(d,n);
        C=cc;
        for(j=0;j<e[i].size();j++){
            if(C==1||e[i][j].y>=now)an[e[i][j].No]=C;
            else{
                while(e[i][j].y<now){
                    if(uu(d,ex[now],ey[now]))C--;
                    now--;
                    if(C==cc)st=now;
                }
                an[e[i][j].No]=C;
            }
        }
        if(uu(record,ex[i],ey[i]))cc--;
    }
    for(i=1;i<=k;i++)printf("%d\n",an[i]);
    return 0;
}