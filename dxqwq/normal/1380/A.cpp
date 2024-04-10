#include<bits/stdc++.h>
int a[1000003];
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int main() {
  int T=read();
  while(T--) {
    int n=read();
    for(int i=1; i<=n; ++i) a[i]=read();
    int maxn=0, pos=0;
    bool flag=0;
    for(int i=2; i<n; ++i) {
      int p1=0, p2=0;
      for(int j=1; j<i; ++j)
        if(a[j]<a[i]) {
          p1=j;
          break;
        }
      for(int j=i+1; j <= n; ++j)
        if(a[j]<a[i]) {
          p2=j;
          break;
        }
      if(p1 && p2) {
        printf("YES\n%d %d %d\n", p1, i, p2);
        flag=1;
        break;
      }
    }
    if(!flag)
      printf("NO\n");
  }
  return 0;
}