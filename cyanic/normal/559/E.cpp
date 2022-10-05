#include<bits/stdc++.h>
#define e(i,a,b) for(int i=a;i<=b;i++)
#define c(a,b) b>a?a=b:0
struct S{int l,r,p;}s[205];
int f[205][205],n,a,b,m,r;
int main(){scanf("%d",&n);
e(i,1,n)scanf("%d%d",&a,&b),s[++m]={a-b,a,i},s[++m]={a,a+b,i};
std::sort(s+1,s+m+1,[&](S a,S b){return a.r<b.r;});
e(i,1,m)f[0][i]=s[i].r-s[i].l;
e(i,0,m)e(j,i+1,m){e(k,j+1,m)
if((!i||s[k].l>s[i].r)&&s[k].p!=s[j].p)
c(f[j][k],f[i][j]+s[k].r-std::max(s[k].l,s[j].r));
c(r,f[i][j]);}printf("%d",r);}