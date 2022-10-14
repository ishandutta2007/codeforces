#include<bits/stdc++.h>
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
const long long p=1e9+9;
signed main()
{
    int a=1,b=4,c=2,n=(read()+1)/2-1;
	while(n--) b*=a,b%=p,c+=b,c%=p,a<<=1,a+=3,a%=p;
    c*=c,c%=p,++c,c<<=1,c%=p;
	printf("%lld\n",c); return 0;
    return 0;
}