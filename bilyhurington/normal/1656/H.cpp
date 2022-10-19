#include<bits/stdc++.h>
using namespace std;
#define ll __int128_t
ll rd(){
    char c=getchar();ll x=0;
    while(c>'9'||c<'0') c=getchar();
    while(c<='9'&&c>='0') x=x*10+c-'0',c=getchar();
    return x;
}
void wrt(ll x){
    if(x>9) wrt(x/10);
    printf("%c",(char)(x%10+'0'));
}
int T,n,m,N;
ll A[1010],B[1010];
ll gcd(ll A,ll B){return B?gcd(B,A%B):A;}
struct Segment_Tree{
    ll val[2050];
    void clear(){memset(val,0,sizeof(val));}
    void upt_val(int k,ll v){
        val[k+=N]=v;
        while(k>1){
            k>>=1;
            val[k]=gcd(val[k<<1],val[k<<1|1]);
        }
    }
}SA[1010],SB[1010];
bool visA[1010],visB[1010];
void solve(){n=rd();m=rd();
    for(N=1;N<=max(n,m);N<<=1);
    for(int i=1;i<=n;i++) A[i]=rd();
    for(int i=1;i<=m;i++) B[i]=rd();
    memset(visA,0,sizeof(visA));
    memset(visB,0,sizeof(visB));
    for(int i=1;i<=n;i++){
        SA[i].clear();
        for(int j=1;j<=m;j++){
            SA[i].upt_val(j,A[i]/gcd(A[i],B[j]));
        }
    }
    for(int i=1;i<=m;i++){
        SB[i].clear();
        for(int j=1;j<=n;j++){
            SB[i].upt_val(j,B[i]/gcd(B[i],A[j]));
        }
    }
    int sizA=n,sizB=m;
    while(sizA&&sizB){
        int ta=0,tb=0;
        for(int i=1;i<=n;i++){
            if(visA[i]) continue;
            if(SA[i].val[1]>1){
                ta=i;
                break;
            }
        }
        if(ta){
            sizA--;visA[ta]=1;
            for(int i=1;i<=m;i++){
                SB[i].upt_val(ta,0);
            }
        }
        for(int i=1;i<=m;i++){
            if(visB[i]) continue;
            if(SB[i].val[1]>1){
                tb=i;
                break;
            }
        }
        if(tb){
            sizB--;visB[tb]=1;
            for(int i=1;i<=n;i++){
                SA[i].upt_val(tb,0);
            }
        }
        if(!ta&&!tb) break;
    }
    if(sizA&&sizB){
        printf("YES\n%d %d\n",sizA,sizB);
        for(int i=1;i<=n;i++) if(!visA[i]) wrt(A[i]),printf(" ");
        puts("");
        for(int i=1;i<=m;i++) if(!visB[i]) wrt(B[i]),printf(" ");
        puts("");
    }else puts("NO");
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}