#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}

signed main()
{
	for(int T=read();T--;)
	{
		int p=read(),a=read(),b=read(),c=read();
		int A=a-(p%a),B=b-(p%b),C=c-(p%c);
		if(A==a) A=0;
		if(B==b) B=0;
		if(C==c) C=0;
		printf("%lld\n",min(A,min(B,C)));
	}
    return 0;
}