    #include<bits/stdc++.h>
    using namespace std;
    const int N=5e5+50,mod=998244353;
    int n,k,m,ans=1,mm,l[N],r[N],f[N],ban[N];
    struct node{
        int l,r,x;
        void init(){scanf("%d%d%d",&l,&r,&x);}
        bool friend operator <(node a,node b){return a.r^b.r?a.r<b.r:a.l>b.l;}
    }a[N],b[N];
    int calc(int x){
        mm=0;  
        for(int i=1;i<=n;i++)ban[i]=0;
        for(int i=1,mx=0;i<=m;i++){
            if(a[i].x>>x&1){ban[a[i].l]++;ban[a[i].r+1]--;}
            else if(a[i].l>mx)b[++mm]=a[i],mx=a[i].l;
        }
        for(int i=1,j=0;i<=n;r[i++]=j){
            ban[i]+=ban[i-1];
            while(j<mm&&b[j+1].l<=i)j++;
        }
        for(int i=n,j=mm+1;i;l[i--]=j)
            while(j>1&&b[j-1].r>=i)j--;
        f[0]=1;int sum=1;
        for(int i=1,j=0;i<=n;i++){
            if(ban[i]){f[i]=0;continue;}
            while(l[i]>r[j]+1)(sum-=f[j++])%=mod;
            f[i]=sum;(sum+=f[i])%=mod;
        }
        int ret=0;
        for(int i=0;i<=n;i++)if(r[i]==mm)(ret+=f[i])%=mod;
        return ret;
    }
    int main(){
        scanf("%d%d%d",&n,&k,&m);
        for(int i=1,l,r,x;i<=m;i++)a[i].init();
        sort(a+1,a+m+1);
        for(int i=0;i<k;i++)ans=1ll*ans*calc(i)%mod;
        cout<<(ans+mod)%mod;
        return 0;
    }