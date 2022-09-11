#include<stdio.h>
#include<algorithm>
using namespace std;
#define MAX 1000000000000000000ll
long long head[64],tail[64],all[64],a[5000],an,ma[64];
int b[250000];
main(){
    int n,m,i,j,k;
    long long now;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d",&k);
        for(j=0;j<k;j++){
            scanf("%I64d",&a[j]);
            all[i]+=a[j];
        }
        head[i]=a[0];
        tail[i]=a[k-1];
        now=a[0];
        for(j=1;j<k;j++){
            now+=a[j];
            head[i]=max(now,head[i]);
        }
        now=a[k-1];
        for(j=k-2;j>=0;j--){
            now+=a[j];
            tail[i]=max(now,tail[i]);
        }
        now=0;
        ma[i]=-MAX;
        for(j=0;j<k;j++){
            if(now<0)now=a[j];
            else now+=a[j];
            ma[i]=max(ma[i],now);
        }
    }
    for(i=0;i<m;i++){
        scanf("%d",&b[i]);
        b[i]--;
    }
    now=tail[b[0]];
    an=ma[b[0]];
    for(i=1;i<m;i++){
        an=max(an,now+max(head[b[i]],0ll));
        an=max(an,ma[b[i]]);
        now=max(max(0ll,now)+all[b[i]],tail[b[i]]);
    }
    printf("%I64d\n",an);
}