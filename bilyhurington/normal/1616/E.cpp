#include<bits/stdc++.h>
using namespace std;
int T,n,posA[100010];
char A[100010],B[100010];
vector<int> vec[30];int tot[30];
int val[100010];
#define lb(x) (x&-x)
void Add(int k,int ad){for(;k<=n;k+=lb(k)) val[k]+=ad;}
int Ask(int k){int t=0;for(;k;k-=lb(k)) t+=val[k];return t;}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d %s %s",&n,A+1,B+1);
        for(int i=0;i<30;i++) vec[i].clear(),tot[i]=0;
        for(int i=1;i<=n;i++) vec[A[i]-'a'].push_back(i),val[i]=0;
        Add(1,n);for(int i=2;i<=n;i++) Add(i,-1);
        long long ans=1e18,sum=0;
        for(int i=1;i<=n;i++){
            if(tot[B[i]-'a']==vec[B[i]-'a'].size()) posA[i]=-1;
            else posA[i]=vec[B[i]-'a'][tot[B[i]-'a']++];
            int nr=n+1;
            for(int j=0;j<B[i]-'a';j++){
                if(tot[j]==vec[j].size()) continue;
                nr=min(nr,Ask(n+1-vec[j][tot[j]]));
            }//printf("%d %d %d\n",i,sum,nr);
            if(nr<=n) ans=min(ans,sum+nr-i);
            if(posA[i]==-1) break;
            sum+=Ask(n+1-posA[i])-i;Add(n+1-posA[i],1);
        }
        printf("%lld\n",ans>1e17?-1:ans);
    }
    return 0;
}