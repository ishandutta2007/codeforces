#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
namespace ZBK{
const int N=2e5+50;
int t,n,a[N],nxt[N],ans;
void main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);ans=1e9;
        memset(nxt,0x3f,sizeof(nxt));
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=n;i;i--)ans=min(ans,nxt[a[i]]-i+1),nxt[a[i]]=i;
        printf("%d\n",ans<=n?ans:-1);
    }
}
}
int main(){ZBK::main();return 0;}