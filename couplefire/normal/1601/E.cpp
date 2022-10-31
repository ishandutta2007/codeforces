#include<bits/stdc++.h>
using namespace std;
int n,q,k,a[300010],M;
long long ans2[300010];
vector<pair<int,int> > G[300010];
int minn[20][300010],Log[300010];
void Pre_ST(){Log[0]=-1;
    for(int i=1;i<=n;i++){
        minn[0][i]=a[i];
        Log[i]=Log[i>>1]+1;
    }
    for(int i=1;i<20;i++){
        for(int j=1;j+(1<<i)-1<=n;j++){
            minn[i][j]=min(minn[i-1][j],minn[i-1][j+(1<<(i-1))]);
        }
    }
}
int get_min(int l,int r){
    int t=Log[r-l+1];
    return min(minn[t][l],minn[t][r-(1<<t)+1]);
}
long long sum[1200010];
int tag[1200010],maxn[1200010];
void Build(int k,int l,int r){
    maxn[k]=2e9;tag[k]=0;
    if(l==r){sum[k]=maxn[k];return;}
    int mid=(l+r)>>1;
    Build(k<<1,l,mid);
    Build(k<<1|1,mid+1,r);
    sum[k]=sum[k<<1]+sum[k<<1|1];
}
void Add(int k,int l,int r,int ad){
    sum[k]=1ll*(r-l+1)*ad;
    tag[k]=ad;maxn[k]=ad;
}
void Push_Down(int k,int l,int r){
    if(!tag[k]) return;
    int mid=(l+r)>>1;
    Add(k<<1,l,mid,tag[k]);
    Add(k<<1|1,mid+1,r,tag[k]);
    tag[k]=0;
}
void Modify(int k,int l,int r,int x,int y,int ad){
    if(maxn[k]<=ad) return;
    if(x<=l&&r<=y){
        if(l==r){
            if(maxn[k]>ad) Add(k,l,r,ad);
        }else{
            int mid=(l+r)>>1;Push_Down(k,l,r);
            if(maxn[k<<1|1]>ad){
                Add(k<<1,l,mid,ad);
                Modify(k<<1|1,mid+1,r,x,y,ad);
            }else Modify(k<<1,l,mid,x,y,ad);
            sum[k]=sum[k<<1]+sum[k<<1|1];
            maxn[k]=max(maxn[k<<1],maxn[k<<1|1]);
        }
        return;
    }
    int mid=(l+r)>>1;Push_Down(k,l,r);
    if(x<=mid) Modify(k<<1,l,mid,x,y,ad);
    if(mid<y) Modify(k<<1|1,mid+1,r,x,y,ad);
    sum[k]=sum[k<<1]+sum[k<<1|1];
    maxn[k]=max(maxn[k<<1],maxn[k<<1|1]);
}
long long Query(int k,int l,int r,int x,int y){
    if(x<=l&&r<=y) return sum[k];
    int mid=(l+r)>>1;long long ans=0;
    Push_Down(k,l,r);
    if(x<=mid) ans+=Query(k<<1,l,mid,x,y);
    if(mid<y) ans+=Query(k<<1|1,mid+1,r,x,y);
    return ans;
}
int main(){
    scanf("%d %d %d",&n,&q,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1,l,r;i<=q;i++){
        scanf("%d %d",&l,&r);
        G[l].push_back(make_pair(r,i));
    }M=n/k;Pre_ST();
    for(int i=n;i>n-k;i--){
        // if(i!=196) continue;
        Build(1,0,M);
        for(int j=i,t=i+1;j>=1;t=j,j-=k){
            // printf("%d %d %d\n",j/k,M,get_min(j,t-1));
            Modify(1,0,M,j/k,M,a[j]);
            if(j<t-1) Modify(1,0,M,j/k+1,M,get_min(j+1,t-1));
            // for(int l=0;l<=M;l++) printf("%lld ",Query(1,0,M,l,l));puts("");
            for(auto pr:G[j]){
                // printf("Q %d %d %d\n",pr.second,j/k,j/k+(pr.first-j)/k);
                ans2[pr.second]=Query(1,0,M,j/k,j/k+(pr.first-j)/k);
            }
        }
    }
    for(int i=1;i<=q;i++) printf("%lld\n",ans2[i]);
    return 0;
}