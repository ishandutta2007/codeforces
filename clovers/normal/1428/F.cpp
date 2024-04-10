#include<bits/stdc++.h>
using namespace std;
const int N=500005;
const int inf=(int)1e9;
typedef long long ll;
int n;
char s[N];

int tot=0;
int mi[N<<2],mp[N<<2],cnt[N<<2],ls[N<<2],rs[N<<2],tag[N<<2];
ll sum[N<<2];
struct Segment{
    void pushup(int x){
        sum[x]=sum[ls[x]]+sum[rs[x]];
        if(mi[ls[x]]<mi[rs[x]]){
            mi[x]=mi[ls[x]];
            cnt[x]=cnt[ls[x]];
            mp[x]=min(mp[ls[x]],mi[rs[x]]);
        }
        else if(mi[ls[x]]==mi[rs[x]]){
            mi[x]=mi[ls[x]];
            cnt[x]=cnt[ls[x]]+cnt[rs[x]];
            mp[x]=min(mp[ls[x]],mp[rs[x]]);
        }
        else{
            mi[x]=mi[rs[x]];
            cnt[x]=cnt[rs[x]];
            mp[x]=min(mp[rs[x]],mi[ls[x]]);
        }
    }
    void pushdown(int x){
        if(!tag[x]) return;
        if(mi[ls[x]]<tag[x]&&ls[x]){
            sum[ls[x]]+=1ll*(tag[x]-mi[ls[x]])*cnt[ls[x]];
            mi[ls[x]]=tag[x];
            tag[ls[x]]=max(tag[x],tag[ls[x]]);
        }
        if(mi[rs[x]]<tag[x]&&rs[x]){
            sum[rs[x]]+=1ll*(tag[x]-mi[rs[x]])*cnt[rs[x]];
            mi[rs[x]]=tag[x];
            tag[rs[x]]=max(tag[x],tag[rs[x]]);
        }
        tag[x]=0;
    }
    void insert(int x,int l,int r,int pos,int val){
        if(l==r){
            mi[x]=val; sum[x]=val;
            mp[x]=inf; cnt[x]=1;
            return;
        }
        int mid=(l+r)>>1;
        pushdown(x);
        if(mid>=pos){
            if(!ls[x]) ls[x]=++tot; 
            insert(ls[x],l,mid,pos,val);
        }
        else{
            if(!rs[x]) rs[x]=++tot;
            insert(rs[x],mid+1,r,pos,val);
        }
        pushup(x);
    }
    void update(int x,int l,int r,int L,int R,int val){//max
        if(mi[x]>=val) return;
        if(L<=l&&r<=R){
            if(mp[x]>val){
                sum[x]+=1ll*cnt[x]*(val-mi[x]);
                mi[x]=val;
                tag[x]=val;
                return;
            }
        }
        int mid=(l+r)>>1;
        pushdown(x);
        if(mid>=L) update(ls[x],l,mid,L,R,val);
        if(mid<R) update(rs[x],mid+1,r,L,R,val);
        pushup(x);
    }
}tree;

void init(){
    tot=1;
    mi[0]=mp[0]=inf;
    scanf("%d",&n);
    scanf("%s",s+1);
}

int t[N];
void solve(){
    int pre=0,beg=0,len=0;
    ll ans=0;
    for(int i=1;i<=n;i++){
        ll res=0;
        if(s[i]=='1'){
            if(!beg) beg=i;
            len++; t[i]=len;
            if(pre) tree.update(1,1,n,1,pre,len);
            res+=1ll*(len+1)*len/2;
            res+=sum[1];
        }
        else{
            if(beg){
                for(int j=pre+1;j<i;j++) t[j]=len-t[j]+1;
            }
            for(int j=pre+1;j<=i;j++){
                tree.insert(1,1,n,j,t[j]);
            }
            res+=sum[1];
            beg=0; len=0; pre=i;
        }
        ans+=res;
    }
    cout<<ans<<endl;
}

int main(){
    init();
    solve();
    return 0;
}