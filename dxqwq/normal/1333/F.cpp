#include<bits/stdc++.h>
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
int num[5000003], prim[5000003];
int t[5000003];
int pn = 0;
void table(int n){
    memset(num, -1, sizeof(num));
    for(int i = 2;i <=n;i++){
        if(num[i]) prim[pn++] = i,t[i]=i;
        for(int j = 0;j<pn&&i*prim[j]<=n;j++){
        	num[i*prim[j]] = 0,t[i*prim[j]]=prim[j];
        	if(i%prim[j]==0) break;
        }
    }
}
int main()
{
	int n=read();
	table(n);
	for(int i=2; i<=n; i++) t[i]=i/t[i];
	sort(t+2,t+n+1);
	for(int i=2; i<=n; i++) printf("%d ",t[i]);
	return 0;
}