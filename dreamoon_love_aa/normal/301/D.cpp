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
#define SIZE 200001
int pos[SIZE];
long long an[SIZE],d[SIZE];
struct data{
    int x,y;
    data(int _x=0,int _y=0){x=min(_x,_y);y=max(_x,_y);}
    bool operator<(const data& b)const{return x<b.x;}
};
struct data2{
    int x,y,No;
    data2(int _x=0,int _y=0,int _No=0){x=min(_x,_y);y=max(_x,_y);No=_No;}
    bool operator<(const data2& b)const{return x<b.x;}
};
vector<data>pp;
vector<data2>qq;
void insert(int x){
    while(x<SIZE){
        d[x]++;
        x+=x&-x;
    }
}
long long query(int x){
    long long res=0;
    while(x){
        res+=d[x];
        x-=x&-x;
    }
    return res;
}
int main(){
    int i,j,k,n,m;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        pos[x]=i;
    }
    for(i=1;i<=n;i++){
        for(j=i;j<=n;j+=i)pp.pb(data(pos[i],pos[j]));
    }
    sort(pp.begin(),pp.end());
    for(i=0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        qq.pb(data2(x,y,i));
    }
    sort(qq.begin(),qq.end());
    int qn=m-1;
    int rn=(int)pp.size()-1;
    for(i=n;i>=1;i--){
        while(rn>=0&&pp[rn].x==i){
            insert(pp[rn--].y);
        }
        while(qn>=0&&qq[qn].x==i){
            an[qq[qn].No]=query(qq[qn].y);
            qn--;
        }
    }
    for(i=0;i<m;i++){
        cout<<an[i]<<endl;
    }
    return 0;
}