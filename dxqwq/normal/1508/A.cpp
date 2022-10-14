// Problem: A. Binary Literature
// Contest: Codeforces - Codeforces Round #715 (Div. 1)
// URL: https://codeforces.com/contest/1508/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
char a[1000003],b[1000003],c[1000003];
char ans[1000003];
signed main()
{
    for(int T=read();T--;)
    {
    	int n=read();
    	scanf("%s",a+1);
    	scanf("%s",b+1);
    	scanf("%s",c+1);
    	int A=0,B=0,C=0;
    	for(int i=1; i<=2*n; i++) if(a[i]=='1') ++A;
    	for(int i=1; i<=2*n; i++) if(b[i]=='1') ++B;
    	for(int i=1; i<=2*n; i++) if(c[i]=='1') ++C;
    	if(A>B) {swap(A,B);
    	for(int i=1; i<=2*n; i++) swap(a[i],b[i]);}
    	if(A>C) {swap(A,C);
    	for(int i=1; i<=2*n; i++) swap(a[i],c[i]);}
    	if(B>C) {swap(B,C);
    	for(int i=1; i<=2*n; i++) swap(c[i],b[i]);}
    	int J,CC=0;
    	if(B<=n)
    	{
    		for(int i=1,j=1; i<=n*2; i++)
    		{
    			for(;j<=n*2&&b[j]=='1';printf("1"),++j,++CC);
    			putchar(a[i]),(j<=2*n&&a[i]==b[j])&&(++j);
    			J=j;
    		}
    		for(int j=J; j<=2*n; ++j) putchar(b[j]),++CC;
    		
    	}
    	else//B>n
    	{
    		for(int i=1,j=1; i<=n*2; i++)
    		{
    			for(;j<=n*2&&b[j]=='0';printf("0"),++j,++CC);
    			putchar(c[i]),(j<=2*n&&c[i]==b[j])&&(++j);
    			J=j;
    		}
    		for(int j=J; j<=2*n; ++j) putchar(b[j]),++CC;
    	}
    	for(int i=CC+1; i<=n; ++i) printf("0");
    	puts("");
    }
	return 0;
}