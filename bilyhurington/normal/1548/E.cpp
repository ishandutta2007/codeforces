#include<bits/stdc++.h>
#ifdef LOCAL_TEST
#include<ctime>
#endif
using namespace std;
int n,m,X,a[200010],b[200010],ma[200010],mb[200010],tmp[200010];
void calc(int *a,int n,int *bef,bool tag=1){
    static int st[200010],stm[200010];
    int tot=0;stm[0]=200001;
    for(int i=1;i<=n;i++){
        while(tot&&((tag&&a[st[tot]]>a[i])||(!tag&&a[st[tot]]>=a[i]))){
            stm[tot-1]=max(stm[tot-1],stm[tot]);
            tot--;
        }
        bef[i]=stm[tot];
        st[++tot]=i;stm[tot]=a[i];
    }
}
vector<int> B[200010];
vector<pair<int,int> > Ar[200010];
namespace BIT{
    int val[200010];
    #define lb(x) (x&-x)
    void add(int k,int ad){for(;k<=200001;k+=lb(k)) val[k]+=ad;}
    int Ask(int k){int t=0;for(;k;k-=lb(k)) t+=val[k];return t;}
    void Add(int l,int r,int ad){
        l=max(l,1);if(l>r) return;
        add(l,ad);add(r+1,-ad);
    }
}
using BIT::Ask;using BIT::Add;
int main(){
    #ifdef LOCAL_TEST
    clock_t start=clock();
    #endif
    scanf("%d %d %d",&n,&m,&X);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++) scanf("%d",&b[i]);
    calc(a,n,ma);reverse(a+1,a+n+1);calc(a,n,tmp,0);
    reverse(a+1,a+n+1);reverse(tmp+1,tmp+n+1);
    for(int i=1;i<=n;i++){
        ma[i]=min(ma[i],tmp[i]);
        Ar[max(0,X-a[i])].push_back(make_pair(X-ma[i]+1,X-a[i]));
        // printf("%d %d %d\n",max(0,X-ma[i]),X-ma[i]+1,X-a[i]);
    }
    calc(b,m,mb);reverse(b+1,b+m+1);calc(b,m,tmp,0);
    reverse(b+1,b+m+1);reverse(tmp+1,tmp+m+1);
    for(int i=1;i<=m;i++){
        mb[i]=min(mb[i],tmp[i]);
        B[mb[i]].push_back(b[i]);
        // printf("%d %d\n",mb[i],a[i]);
    }
    long long ans=0;
    for(int i=0;i<=200001;i++){
        for(auto t:B[i]) ans+=Ask(t);
        for(auto pr:Ar[i]) Add(pr.first,pr.second,1);
    }
    printf("%lld\n",ans);
    #ifdef LOCAL_TEST
    clock_t end=clock();cout<<endl;
    cout<<"The program costs "<<(double)(end-start)/CLOCKS_PER_SEC<<" seconds"<< endl;
    puts("");system("pause");
    #endif
    return 0;
}
//X-ma[i]<b[i]<=X-a[i]
//mb[i]>X-a[i]