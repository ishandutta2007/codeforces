#include<bits/stdc++.h>
using namespace std;

const int bs=10;

int n,m;
int a[100005];
int cnt[100005],pos[100005],laz[100005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    scanf("%d%d",&n,&m);
    for(int x=0;x<n;x++)scanf("%d",a+x);
    for(int x=n-1;x>=0;x--){
        int np=min(((x>>bs)+1)<<bs,n);
        if(x+a[x]>=np){
            cnt[x]=0;
            pos[x]=x;
        }else{
            cnt[x]=cnt[x+a[x]]+1;
            pos[x]=pos[x+a[x]];
        }
    }
    while(m--){
        int typ,x;
        scanf("%d%d",&typ,&x);
        x--;
        if(typ==1){
            int sum=0,lp;
            while(x<n){
                if(laz[x>>bs]){
                    laz[x>>bs]=0;
                    int ed=min(((x>>bs)+1)<<bs,n)-1,st=(x>>bs)<<bs;
                    for(int i=ed;i>=st;i--){
                        if(i+a[i]>=ed){
                            cnt[i]=0;
                            pos[i]=i;
                        }else{
                            cnt[i]=cnt[i+a[i]]+1;
                            pos[i]=pos[i+a[i]];
                        }
                    }
                }
                sum=sum+cnt[x]+1;
                lp=pos[x];
                x=pos[x]+a[pos[x]];
            }
            printf("%d %d\n",lp+1,sum);
        }else{
            scanf("%d",a+x);
            laz[x>>bs]=1;
        }
    }

    return 0;
}