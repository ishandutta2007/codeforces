#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[1003];
long long x[1003][1003];//ij
int main()
{
    int n=read(),m=read();
    for(int i=1; i<=n; i++) a[i]=read();
    a[0]=-1919810;
    sort(a+1,a+n+1);
    int Max=a[n];
    long long ans=0;
    for(int t=1; t*(m-1)<=a[n]; t++)
    {
        int tmp=0;
        for(int i=0; i<=n; i++) x[i][0]=1;
        for(int i=1; i<=n; i++) 
        {
            while(a[tmp]<=a[i]-t) tmp++;
		    for(int j=1; j<=m; j++) x[i][j]=(x[i-1][j]+x[tmp-1][j-1])%998244353LL;
        }
        ans+=x[n][m],ans%=998244353LL;
    }
    cout<<ans<<endl;
	return 0;
}