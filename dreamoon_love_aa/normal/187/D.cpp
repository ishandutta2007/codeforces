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
#define SIZE 400011
using namespace std;
long long l[SIZE],g,r,q[SIZE],gr,dp[SIZE*2];
int n;
struct ADD{
    long long x,v;
    ADD(long long _x=0,long long _v=0){x=_x,v=_v;}
};
vector<ADD>e[SIZE*2];
struct data{
    long long No,v;
    data(long long _No=0,long long _v=0){No=_No,v=_v;}
    bool operator<(const data &b)const{return v<b.v||(v==b.v&&No<b.No);}
};
set<data>H;
int main(){
    int i,j,k,Q;
    long long base=0;
    scanf("%d%I64d%I64d",&n,&g,&r);
    gr=g+r;
    for(i=1;i<=n+1;i++){scanf("%I64d",&l[i]);base+=l[i];}
    scanf("%d",&Q);
    for(i=1;i<=Q;i++){
        scanf("%I64d",&q[i]);
        H.insert(data(i,q[i]%gr));
    }
    long long now=0;
    for(i=1;i<=n;i++){
        now=(now+l[i])%gr;
        long long bb=(g+gr-now)%gr;
        set<data>::iterator ll=H.lower_bound(data(0,bb)),rr;
        for(rr=ll;rr!=H.end()&&rr->v-bb<r;rr++){
            e[Q+i].pb(ADD(rr->No,r-(rr->v-bb)));
        }
        if(ll!=H.end())H.erase(ll,rr);
        if(bb+r>gr){
            for(rr=H.begin();rr!=H.end()&&rr->v+(gr-bb)<r;rr++){
                e[Q+i].pb(ADD(rr->No,r-(rr->v+(gr-bb))));
            }
            H.erase(H.begin(),rr);
        }
        H.insert(data(Q+i,(gr-now)%gr));
    }
    for(i=Q+n;i>Q;i--){
        for(j=0;j<(int)e[i].size();j++){
            //printf("(%I64d,%I64d)\n",e[i][j].x,e[i][j].v);
            dp[e[i][j].x]=dp[i]+e[i][j].v;
        }
    }
    for(i=1;i<=Q;i++)printf("%I64d\n",base+dp[i]+q[i]);
    return 0;
}