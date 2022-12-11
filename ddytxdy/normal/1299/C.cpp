#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e6+50;
int n,a[N],st[N],tp;double sum[N];LL s[N];
int read(){
    int x=0,c;
    while(!isdigit(c=getchar()));
    while(isdigit(c))x=x*10+c-48,c=getchar();
    return x;
}
int main(){
    n=read();
    for(int i=1;i<=n;i++)s[i]=s[i-1]+(a[i]=read());
    for(int i=1,la;i<=n;i++){
        la=i;
        while(tp&&sum[tp]/(la-st[tp])>1.0*(s[i]-s[st[tp]-1])/(i+1-st[tp]))la=st[tp--];
        if(la)st[++tp]=la,sum[tp]=s[i]-s[la-1];
        else st[++tp]=i,sum[tp]=a[i];
    }
    st[++tp]=n+1;
    for(int i=1,j=0;i<=n;i++){
        while(j<tp&&st[j+1]<=i)j++;
        printf("%.10f\n",sum[j]/(st[j+1]-st[j]));
    }
    return 0;
}