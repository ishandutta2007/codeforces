#include<bits/stdc++.h>
using namespace std;
int n,m,a[123456];
int main(){
    int t=1; while(t--){
        cin>>n>>m;
        long long c=(n+1ll)*n;
        for(int i=1;i<=n;++i) scanf("%d",a+i);
        for(int i=1;i<=n;++i) c+=((a[i]!=a[i-1])*(i-1ll)*(n-i+1)+(a[i]!=a[i+1])*1ll*i*(n-i));
        //cout<<c<<endl;
        while(m--){
            int i,x; scanf("%d%d",&i,&x);
            c-=((a[i]!=a[i-1])*(i-1ll)*(n-i+1)+(a[i]!=a[i+1])*1ll*i*(n-i))*2;
            //cerr<<c<<endl;
            a[i]=x;
            c+=((a[i]!=a[i-1])*(i-1ll)*(n-i+1)+(a[i]!=a[i+1])*1ll*i*(n-i))*2;
            printf("%lld\n",c/2);
        }
    }
}