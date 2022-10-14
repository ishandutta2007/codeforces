#include<bits/stdc++.h>
inline long long readll(){
   long long s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
long long a[1919810],pre[1919810];
using namespace std;
map<long long,int> M;
long long ans=0;
int main()
{
	int n;
  scanf("%d",&n);
  M[0]=0;
  int Mx=-1;
  for(int i=1; i<=n; i++)
  {
  	a[i]=readll(),pre[i]=pre[i-1]+a[i];
  	if(M.count(pre[i])) Mx=max(Mx,M[pre[i]]);
  	M[pre[i]]=i;
  	ans+=max(i-Mx-1,0);
  }
  printf("%lld",ans);
  return 0;
}