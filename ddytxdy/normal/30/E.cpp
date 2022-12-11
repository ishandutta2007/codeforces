#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
char s[N],is[N];int n,len[N],z[N],a[N],p[N],mx[N],ans,l1,p1,l2,p2,l3,p3;
int main(){
    scanf("%s",s+1);z[1]=n=strlen(s+1);
    memcpy(is,s,sizeof(s));reverse(is+1,is+n+1);
    for(int i=1,r=0,m=0;i<=n;i++){
        if(i<=r)len[i]=min(r-i+1,len[2*m-i]);
        while(i+len[i]<=n&&s[i+len[i]]==s[i-len[i]])len[i]++;
        if(i+len[i]-1>r)r=i+len[i]-1,m=i;
    }
    for(int i=2,r=0,l=0;i<=n;i++){
        if(i<=r)z[i]=min(r-i+1,z[i-l+1]);
        while(i+z[i]<=n&&is[i+z[i]]==is[1+z[i]])z[i]++;
        if(i+z[i]-1>r)r=i+z[i]-1,l=i;
    }
    for(int i=1,r=0,l=0;i<=n;i++){
        if(i<=r)a[i]=min(r-i+1,z[i-l+1]);
        while(i+a[i]<=n&&s[i+a[i]]==is[1+a[i]])a[i]++;
        if(i+a[i]-1>r)r=i+a[i]-1,l=i;
    }
    for(int i=1,j=0;i<=n;i++)
        while(a[i]>j)p[++j]=i,mx[i+j-1]=j;
    for(int i=1;i<=n;i++)mx[i]=max(mx[i],mx[i-1]);
    for(int i=1;i<=n;i++){
        int dat=min(mx[i-len[i]],n-(i+len[i]-1));
        if(len[i]*2-1+2*dat>ans){
            ans=len[i]*2-1+2*dat;
            p1=p[dat];l1=dat;
            p2=i-len[i]+1;l2=2*len[i]-1;
            p3=n-dat+1;l3=dat;
        }
    }
    if(!l1)printf("1\n%d %d\n",p2,l2);
    else printf("3\n%d %d\n%d %d\n%d %d\n",p1,l1,p2,l2,p3,l3);
    return 0;
}