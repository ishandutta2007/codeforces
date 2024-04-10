#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define mx 20
#define int long long
#define inf 1000000000000000000
using namespace std;
int n,a[400005],num[21][1100005],x[1100005];
int f[1100005];
int cnt[25];
inline void work(int now){
    memset(cnt,0,sizeof(cnt));
    register int nownum=0,nowsum=0,last=1;
    for (register int i=1;i<=n;i++){
        if (a[i]==now)nowsum+=i-last,last++;
    }
    for (register int i=n;i>=1;i--){
        if (a[i]==now)nownum++;
        else cnt[a[i]]+=nownum;
    }
    for (register int j=0;j<=((1<<mx)-1);j++){
        num[now][j]=nowsum;
        for (register int k=1;k<=mx;k++){
            if ((j&(1<<(k-1)))!=0)num[now][j]-=cnt[k];
        }
    }
    return;
}
inline int count(int x){
    register int ans=0;
    while(x>0)ans++,x-=(x&(-x));
    return ans;
}
bool cmp(int x,int y){
    return count(x)<count(y);
}
signed main(){
    cin>>n;
    for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for (int i=1;i<=mx;i++)work(i);
    for (int i=0;i<=((1<<mx)-1);i++)
            f[i]=inf;
    f[0]=0;
    for (register int i=1;i<=((1<<mx)-1);i++){
        x[i]=i;
    }
    sort(x+1,x+1+((1<<mx)-1),cmp);
    for (register int ii=1;ii<=(1<<mx)-1;ii++){
        int i=x[ii];
        for (register int k=1;k<=mx;k++){
            if ((i&(1<<(k-1)))!=0)
                f[i]=min(f[i],num[k][i^(1<<(k-1))]+f[i^(1<<(k-1))]);
        }
    }
    cout<<f[(1<<mx)-1]<<endl;
    return 0;
}