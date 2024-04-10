/*
 * @Author: BilyHurington
 * @Date: 2021-06-29 14:03:12
 * @LastEditors: BilyHurington
 * @LastEditTime: 2021-06-29 14:26:46
 */
#include<bits/stdc++.h>
#ifdef LOCAL_TEST
#include<ctime>
#endif
using namespace std;
int n,k,a[100010],pos[100010];
long long f[100010],g[100010];
long long now;int L=1,R,cnt[100010];
void Add(int x){now+=cnt[x];cnt[x]++;}
void Del(int x){cnt[x]--;now-=cnt[x];}
void Goto(int l,int r){
    while(L>l) Add(a[--L]);
    while(R<r) Add(a[++R]);
    while(L<l) Del(a[L++]);
    while(R>r) Del(a[R--]);
}
void divide(int l,int r,int pl,int pr){
    if(l>r) return;
    int mid=(l+r)>>1;
    long long minn=1e18;
    for(int i=pl;i<=min(pr,mid);i++){
        Goto(i,mid);
        if(minn>now+f[i-1]) pos[mid]=i,minn=now+f[i-1];
    }g[mid]=minn;
    divide(l,mid-1,pl,pos[mid]);
    divide(mid+1,r,pos[mid],pr);
}
int main(){
    #ifdef LOCAL_TEST
    clock_t start=clock();
    #endif
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    f[0]=0;for(int i=1;i<=n;i++) f[i]=1e18;
    for(int i=1;i<=k;i++){
        divide(1,n,1,n);
        memcpy(f,g,sizeof(g));
        f[0]=1e18;
    }
    printf("%lld",f[n]);
    #ifdef LOCAL_TEST
    clock_t end=clock();cout<<endl;
    cout<<"The program costs "<<(double)(end-start)/CLOCKS_PER_SEC<<" seconds"<< endl;
    puts("");system("pause");
    #endif
    return 0;
}