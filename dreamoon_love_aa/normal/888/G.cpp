
#include<bits/stdc++.h>
#define PB push_back
using namespace std;
const int MM = 5000;
const int SIZE = 2e5+10;
int p[SIZE];
long long an;
int get(int x,int v){
        return (x>>v)&1;
}
const int NUM = 1e7;
int nxt[NUM][2],nn,num[NUM];
int mi;
void g(int v,int id1,int id2){
        if(nxt[id1][0]==-1&&nxt[id1][1]==-1){
                mi=min(mi,v);
                return;
        }
        for(int j=0;j<2;j++)if(nxt[id1][j]!=-1){
                if(nxt[id2][j]!=-1)g(v*2,nxt[id1][j],nxt[id2][j]);
                else g(v*2+1,nxt[id1][j],nxt[id2][j^1]);
        }
}
int merge(int id1,int id2){
        if(num[id1]>num[id2])swap(id1,id2);
        mi=2147483647;
        g(1,id1,id2);
        return mi;
}
int f(int lv,int L,int R){
        num[nn]=R-L+1;
        nxt[nn][0]=nxt[nn][1]=-1;
        int me=nn++;
        if(lv<0) return me;
        int mid=L;
        while(mid<=R&&!get(p[mid],lv))mid++;
        if(mid>L)nxt[me][0]=f(lv-1,L,mid-1);
        if(mid<=R)nxt[me][1]=f(lv-1,mid,R);
        if(nxt[me][0]!=-1&&nxt[me][1]!=-1)an+=merge(nxt[me][0],nxt[me][1]);
        return me;
}
int main(){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",&p[i]);
        sort(p,p+n);
        f(29,0,n-1);
        cout<<an<<endl;
}