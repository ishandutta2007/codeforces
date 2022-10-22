//
#include<bits/stdc++.h>
using namespace std;
int f[20][20];
int main(){
int n,ans=0;
scanf("%d",&n);
f\
o\
r (int i=1;i<=n;++i) 
f\
o\
r (int j=1;j<=n;++j) scanf("%d",&f[i][j]);
f\
o\
r (int k=1;k<=n;++k)
f\
o\
r (int i=1;i<=n;++i)
f\
o\
r (int j=1;j<=n;++j)
f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
f\
o\
r (int i=1;i<=n;++i)
f\
o\
r (int j=1;j<=n;++j)
ans=max(ans,f[i][j]);
printf("%d",ans);
return 0;
}