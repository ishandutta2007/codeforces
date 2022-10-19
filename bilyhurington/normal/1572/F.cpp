#include<bits/stdc++.h>
#ifdef LOCAL_TEST
#include<ctime>
#endif
using namespace std;
int n,q;
namespace BIT{
    long long v1[200010],v2[200010];
    #define lb(x) (x&-x)
    void Add(int x,long long ad){
        // printf("Add %d %lld\n",x,ad);
        for(int i=x;i<=n;i+=lb(i)){
            v1[i]+=ad;
            v2[i]+=x*ad;
        }
    }
    void Add(int l,int r,int ad){Add(l,ad);Add(r+1,-ad);}
    long long Ask(int x){
        long long ans=0;
        for(int i=x;i;i-=lb(i)) ans+=(x+1)*v1[i]-v2[i];
        return ans;
    }
    long long Ask(int l,int r){return Ask(r)-Ask(l-1);}
}
using BIT::Add;
using BIT::Ask;
namespace Segment_Beats{
    int maxn[800010],maxc[800010],max2[800010],tag[800010];
    void Upt(int k){
        if(maxn[k<<1]==maxn[k<<1|1]){
            maxn[k]=maxn[k<<1];
            maxc[k]=maxc[k<<1]+maxc[k<<1|1];
            max2[k]=max(max2[k<<1],max2[k<<1|1]);
        }else if(maxn[k<<1]>maxn[k<<1|1]){
            maxn[k]=maxn[k<<1];
            maxc[k]=maxc[k<<1];
            max2[k]=max(max2[k<<1],maxn[k<<1|1]);
        }else{
            maxn[k]=maxn[k<<1|1];
            maxc[k]=maxc[k<<1|1];
            max2[k]=max(maxn[k<<1],max2[k<<1|1]);
        }
    }
    void Build(int k,int l,int r){
        tag[k]=2e9;
        if(l==r){
            maxn[k]=l;
            maxc[k]=1;
            max2[k]=-1;
            return;
        }
        int mid=(l+r)>>1;
        Build(k<<1,l,mid);
        Build(k<<1|1,mid+1,r);
        Upt(k);
    }
    void Put_Tag(int k,int t){
        if(maxn[k]<=t) return;
        maxn[k]=t;tag[k]=t;
    }
    void Push_Down(int k){
        if(tag[k]>1e9) return;
        Put_Tag(k<<1,tag[k]);
        Put_Tag(k<<1|1,tag[k]);
        tag[k]=2e9;
    }
    void Modify(int k,int l,int r,int x,int val){
        if(l==r){
            // printf("%d %d\n",l,k);
            if(maxn[k]<val) Add(maxn[k]+1,val,1);
            else Add(val+1,maxn[k],-1);
            maxn[k]=val;
            return;
        }
        int mid=(l+r)>>1;
        Push_Down(k);
        if(x<=mid) Modify(k<<1,l,mid,x,val);
        else Modify(k<<1|1,mid+1,r,x,val);
        Upt(k);
    }
    void Modify_min(int k,int l,int r,int x,int y,int val){
        if(maxn[k]<=val) return;
        if(x<=l&&r<=y){
            if(max2[k]<=val){
                Add(val+1,maxn[k],-maxc[k]);
                Put_Tag(k,val);
            }else{
                int mid=(l+r)>>1;Push_Down(k);
                Modify_min(k<<1,l,mid,x,y,val);
                Modify_min(k<<1|1,mid+1,r,x,y,val);
                Upt(k);
            }
            return;
        }
        int mid=(l+r)>>1;Push_Down(k);
        if(x<=mid) Modify_min(k<<1,l,mid,x,y,val);
        if(mid<y) Modify_min(k<<1|1,mid+1,r,x,y,val);
        Upt(k);
    }
}
using namespace Segment_Beats;
int main(){
    #ifdef LOCAL_TEST
    clock_t start=clock();
    #endif
    scanf("%d %d",&n,&q);Build(1,1,n);Add(1,n,1);
    int opt,x,y;while(q--){
        scanf("%d %d %d",&opt,&x,&y);
        if(opt==1){
            Modify(1,1,n,x,y);
            if(x>1) Modify_min(1,1,n,1,x-1,x-1);
        }else printf("%lld\n",Ask(x,y));
    }
    #ifdef LOCAL_TEST
    clock_t end=clock();cout<<endl;
    cout<<"The program costs "<<(double)(end-start)/CLOCKS_PER_SEC<<" seconds"<< endl;
    puts("");system("pause");
    #endif
    return 0;
}