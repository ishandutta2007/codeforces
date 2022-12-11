#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int t,n,k,a[N],ans=2e9+10,x;
void cmin(int &x,int y){y<x?x=y:0;}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);k++;ans=2e9+10;
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=n-k+1;i++){
            int l=i,r=i+k-1;
            int p=(a[l]+a[r])>>1;
            int now=max(a[r]-p,p-a[l]);
            if(now<ans)cmin(ans,now),x=p;
        }
        printf("%d\n",x);
    }
    return 0;
}