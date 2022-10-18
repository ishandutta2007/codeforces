#include<bits/stdc++.h>

using namespace std;

const int maxn=5010;

struct seg{
    int l,r,p;
};

seg h[maxn],v[maxn];
int n;
int hc,vc;
int idx[maxn*2];
long long bit[maxn*2];
seg q[maxn];

int lbt(int x){
    return x&(-x);
}

void chg(int i,int v){
    while(i<maxn*2){
        bit[i]+=v;
        i+=lbt(i);
    }
}
long long qry(int i){
    long long ans=0;
    while(i){
        ans+=bit[i];
        i-=lbt(i);
    }
    return ans;
}
bool cmp(seg a,seg b){
    return a.p<b.p;
}

bool cmp2(seg a,seg b){
    return a.r<b.r;
}


int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    
    for(int i=1;i<=n;i++){
        int xa,ya,xb,yb;
        cin>>xa>>ya>>xb>>yb;
        xa+=5002;xb+=5002;ya+=5002;yb+=5002;
        if(xa==xb){
            ++vc;
            v[vc].p=xa;
            if(yb>ya) swap(yb,ya);
            v[vc].l=yb;
            v[vc].r=ya;
        }
        if(ya==yb){
            ++hc;
            h[hc].p=ya;
            if(xb>xa) swap(xb,xa);
            h[hc].l=xb;
            h[hc].r=xa;
        }
    }
    sort(h+1,h+1+hc,cmp);
    sort(v+1,v+1+vc,cmp2);
    long long ans=0;
    for(int i=1;i<hc;i++){
        memset(bit,0,sizeof(bit));
        int sz=0,cp=1;
        for(int j=1;j<=vc;j++){
            if(v[j].p>=h[i].l&&v[j].p<=h[i].r&&v[j].l<=h[i].p&&v[j].r>=h[i].p){
                chg(v[j].p,1);
                q[++sz]=v[j];
            }
        }
        for(int j=i+1;j<=hc;j++){
            while(cp<=sz&&q[cp].r<h[j].p){
                chg(q[cp].p,-1);
                cp++;
            }
            long long cur=qry(h[j].r)-qry(h[j].l-1);
            ans+=(cur*(cur-1))/2;
        }
    }
    cout<<ans;
    return 0;
}