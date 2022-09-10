#include<bits/stdc++.h>
using namespace std;
int n,m;
int AA[100010];
int l[301],r[301];
int ll[301],rr[301];
int d[603],dn;
vector<int>res;
int an;
int mii[603],maa[603];
int sub[602];
int u[301],tt;
int xx=-1,yy;
void check(int x,int y,int final_round){
    tt++;
    memset(sub,0,sizeof(sub));
    for(int i=0;i<m;i++){
        if(ll[i]<=x&&x<rr[i]
        &&(ll[i]>y||rr[i]<=y)){
            u[i]=tt;
            sub[ll[i]]++;
            sub[rr[i]]--;
        }
    }
    int ma=maa[0]-sub[0],mi=mii[0]-sub[0];
    if(final_round){
        res.clear();
        for(int i=0;i<m;i++){
            if(u[i]==tt)res.push_back(i+1);
        }
        return;
    }
    for(int i=0;i<dn-1;i++){
        if(i)sub[i]+=sub[i-1];
        ma=max(ma,maa[i]-sub[i]);
        mi=min(mi,mii[i]-sub[i]);
    }
    if(ma-mi>an){
        xx=x,yy=y;
        an=ma-mi;
    }
}
int main(){
    d[dn++]=0;
    scanf("%d%d",&n,&m);
    d[dn++]=n;
    for(int i=0;i<n;i++)scanf("%d",&AA[i]);
    for(int i=0;i<m;i++){
        scanf("%d%d",&l[i],&r[i]);
        l[i]--;
        d[dn++]=l[i];
        d[dn++]=r[i];
    }
    sort(d,d+dn);
    dn=unique(d,d+dn)-d;
    for(int i=0;i<m;i++){
        ll[i]=lower_bound(d,d+dn,l[i])-d;
        rr[i]=lower_bound(d,d+dn,r[i])-d;
    }
    for(int i=0;i<dn-1;i++){
        mii[i]=maa[i]=AA[d[i]];
        for(int j=d[i];j<d[i+1];j++){
            mii[i]=min(mii[i],AA[j]);
            maa[i]=max(maa[i],AA[j]);
        }
    }
    int mi=AA[0];
    int ma=AA[0];
    for(int i=0;i<n;i++){
        mi=min(mi,AA[i]);
        ma=max(ma,AA[i]);
    }
    an=ma-mi;
    for(int i=0;i<dn-1;i++)
        for(int j=0;j<dn-1;j++){
            if(i==j)continue;
            check(i,j,0);
        }
        if(xx!=-1)
    check(xx,yy,1);
    printf("%d\n%d\n",an,(int)res.size());
    if(res.size()){
        for(int i=0;i<res.size();i++) printf("%d%c",res[i]," \n"[i==res.size()-1]);
    }
    return 0;
}