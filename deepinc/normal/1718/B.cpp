#include<bits/stdc++.h>
using namespace std;
int n,m,a[123456],ok[123456];
long long f[66],s[66];
int main(){
    f[1]=s[1]=1;
    for(int i=2;i<=60;++i) f[i]=f[i-1]+f[i-2], s[i]=s[i-1]+f[i];
    int t; cin>>t; while(t--){
        cin>>n;
        int S=0,c=0,C=0;
        for(int i=1,x;i<=n;++i){ 
            scanf("%d",&x); S+=x;
            int z=0;
            while(f[z]<=x)z++;
            z--; a[++c]=f[z]; x-=f[z]; ok[c]=x?0:1;
            while(x) {while(f[z]>x) z--; x-=f[z]; a[++c]=f[z]; ok[c]=x?0:1;} 
        }
        while(S>s[C]) C++;
        if(S!=s[C]) goto gg;
        for(int i=1;i<=c;++i) if(a[i]==f[C-c+1<<1]&&ok[i]) {int t=C-c;for(int j=1;j<=t;++j) a[++c]=f[j+j-1]; a[i]=f[t+t+1]; break;}
        sort(a+1,a+1+c);
        //for(int i=1;i<=c;++i) cerr<<a[i]<<' '; puts("");
        for(int i=1;i<=c;++i) if(a[i]!=f[i]) goto gg;
        puts("Yes"); continue; gg:puts("No");
    }
}