#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=300006;

struct node{
    node* c[2];
    long long mx;
};

node pool[maxn<<2];int ps;

node* nwnode(){
    node* nw=pool+ps++;
    return nw;
}

void pu(node* rt){
    rt->mx=max(rt->c[0]->mx,rt->c[1]->mx);
}

node* bt(int l,int r){
    node* rt=nwnode();
    if(l!=r){
        rt->c[0]=bt(l,(l+r)/2);
        rt->c[1]=bt((l+r)/2+1,r);
        pu(rt);
    }else rt->mx=LLONG_MIN;
    return rt;
}


void chg(node*rt,int cl,int cr,int i,long long v){
    int cm=(cl+cr)/2;
    if(cl==cr){
        rt->mx=v;
        return;
    }else if(i<=cm)chg(rt->c[0],cl,cm,i,v);
    else chg(rt->c[1],cm+1,cr,i,v);
    pu(rt);
}

long long qry(node* rt,int cl,int cr,int l,int r){
    int cm=(cl+cr)/2;
    if(cl==l&&cr==r){
        return rt->mx;
    }else if(r<=cm)return qry(rt->c[0],cl,cm,l,r);
    else if(l>cm)return qry(rt->c[1],cm+1,cr,l,r);
    else{
        return max(qry(rt->c[0],cl,cm,l,cm),qry(rt->c[1],cm+1,cr,cm+1,r));
    }
}

int n;
int h[maxn];
int b[maxn];

int stk[maxn],sp;
int sr[maxn];
long long sv[maxn],dp[maxn];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>h[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    multiset<long long,greater<long long> > val;
    node* rt=bt(0,n);
    chg(rt,0,n,0,0);
    for(int i=1;i<=n;i++){
        while(sp&&h[i]<stk[sp]){
            val.erase(val.find(sv[sp]));
            --sp;
        }
        int l=sr[sp],r=i-1;
        long long cdp=b[i]+qry(rt,0,n,l,r);
        ++sp;
        sr[sp]=i;sv[sp]=cdp;stk[sp]=h[i];
        val.insert(cdp);
        dp[i]=*val.begin();
        chg(rt,0,n,i,dp[i]);
    }
    cout<<dp[n];
    return 0;
}