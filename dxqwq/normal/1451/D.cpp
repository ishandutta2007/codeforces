#include<bits/stdc++.h>
#define mp make_pair
#define pi pair<int,int>
#define pb push_back
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[100003];
bool cmp(int x,int y) { return x>y; }
int mian()
{
	int d=read(),k=read(),n=1;
	a[1]=d/k+1;
	for(int i=k; i<=d; i+=k) a[++n]=((int)sqrt(1ll*d*d-1ll*i*i))/k+1;
	int x=0;
	for(int i=1; i<=n; i++) if(a[i]>=i) x=i; else break;
	int y=0,z=a[x]-x;
	for(int i=x+1; i<=n; i++) if(a[i]>=x) ++y; else break;
	if((y&1)||(z&1)) puts("Ashish"); 
	else puts("Utkarsh");
	return 0;
}
int main()
{
	for(int T=read();T--;) mian();
	return 0;
}