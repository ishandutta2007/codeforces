//  zhoukangyang 
#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
bool a[1003];
int A[250003],B[250003];
signed main()
{
	int m=read();
	int n=read();
	for(int i=1; i<=n; i++) a[read()]=1;
	if(a[m]) puts("1"),exit(0);
	memset(A,0x3f,sizeof(A)),memset(B,0x3f,sizeof(B));
	A[0]=0;
	for(int i=m+1,g=1; i<=1000; i++,g++) if(a[i]) for(int j=0; j+g<=250000; ++j) (A[j+g]>A[j]+1)&&(A[j+g]=A[j]+1);
	B[0]=0;
	for(int i=m-1,g=1; i>=0; i--,g++) if(a[i]) for(int j=0; j+g<=250000; ++j) (B[j+g]>B[j]+1)&&(B[j+g]=B[j]+1);
	int Ans=0x3f3f3f3f;
	for(int i=1; i<=250000; ++i) (Ans>A[i]+B[i])&&(Ans=A[i]+B[i]);
	if(Ans==0x3f3f3f3f) puts("-1");
	else printf("%d\n",Ans); 
    return 0;
}