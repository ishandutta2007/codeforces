#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n,m,c,a[N],p[N],mm,ll,rr,fl;
int main(){
    scanf("%d%d%d",&n,&m,&c);mm=c/2;ll=0;rr=n+1;
    for(int i=1;i<=mm;i++)p[i]=0;for(int i=mm+1;i<=c;i++)p[i]=n+1;
    for(int i=1,x;i<=m;i++){
        scanf("%d",&x);
        if(x<=mm){
            if(fl&&p[x]==ll)printf("%d ",ll);
            else printf("%d\n",++p[x]);ll=max(ll,p[x]);cout.flush();
            if(ll==rr-1)fl=1;
            for(int j=x+1;j<=mm;j++)p[j]=max(p[j],p[x]);
        }
        else{
            if(fl&&p[x]==rr)printf("%d ",rr);
            else printf("%d\n",--p[x]);rr=min(rr,p[x]);cout.flush();
            if(ll==rr-1)fl=1;
            for(int j=mm+1;j<x;j++)p[j]=min(p[j],p[x]);
        }
    }
    return 0;
}