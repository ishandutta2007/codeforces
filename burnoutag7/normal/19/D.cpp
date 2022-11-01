#include<bits/stdc++.h>
using namespace std;

int n,m,sz;
int dat[800005];
set<int> pts[200005];
pair<char,pair<int,int>> q[200005];
map<int,int> mp;
int rmp[200005];

void upd(int pos,int val){
    pos+=sz-1;
    dat[pos]=val;
    while(pos>1){
        pos>>=1;
        dat[pos]=max(dat[pos<<1],dat[pos<<1|1]);
    }
}

int qry(int bk,int l,int r,int pos,int val){
    if(dat[bk]<val||r<pos)return 1e9;
    if(l==r)return l;
    int tmp=qry(bk<<1,l,l+r>>1,pos,val);
    if(tmp!=(int)1e9)return tmp;
    return qry(bk<<1|1,(l+r>>1)+1,r,pos,val);
}

int main(){

    scanf("%d",&n);
    {
        char buf[10];
        for(int i=1;i<=n;i++){
            scanf("%s%d%d",buf,&q[i].second.first,&q[i].second.second);
            mp[q[i].second.first]=0;
            q[i].first=*buf;
        }
    }
    for(pair<const int,int> &p:mp){
        p.second=++m;
        rmp[m]=p.first;
    }
    sz=1;while(sz<m)sz<<=1;
    for(int i=1;i<=n;i++){
        q[i].second.first=mp[q[i].second.first];
        const char &op=q[i].first;
        const int &x=q[i].second.first;
        const int &y=q[i].second.second;
        if(op=='a'){
            pts[x].insert(y);
            upd(x,*pts[x].rbegin());
        }else if(op=='r'){
            pts[x].erase(y);
            if(pts[x].empty())upd(x,0);
            else upd(x,*pts[x].rbegin());
        }else{
            int rx=qry(1,1,sz,x+1,y+1);
            if(rx==(int)1e9)puts("-1");
            else printf("%d %d\n",rmp[rx],*pts[rx].upper_bound(y));
        }
    }

    return 0;
}