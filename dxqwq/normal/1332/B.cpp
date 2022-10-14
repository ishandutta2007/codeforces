#include<bits/stdc++.h>
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
set<int> S;
int a[1003],b[1003],c[1003];
int n,m;
int main(){
    int t=read();
    while(t--)
    {
    	int n=read();
    	for(int i=1; i<=n; i++) a[i]=read();
    	
		int cnt=0;
		for(int i=1; i<=n; i++) 
		{
			if(a[i]%2) if(a[i]%3) if(a[i]%5) if(a[i]%7) if(a[i]%11) if(a[i]%13) if(a[i]%17) if(a[i]%19) if(a[i]%23) if(a[i]%29) if(a[i]%31)
			b[i]=a[i]=114514+i;
			else b[i]=a[i]=31;
			else b[i]=a[i]=29;
			else b[i]=a[i]=23;
			else b[i]=a[i]=19;
			else b[i]=a[i]=17;
			else b[i]=a[i]=13;
			else b[i]=a[i]=11;
			else b[i]=a[i]=7;
			else b[i]=a[i]=5;
			else b[i]=a[i]=3;
			else b[i]=a[i]=2;
		}
		sort(b+1,b+n+1);
    int len=unique(b+1,b+n+1)-b-1;//unique 
	for( int i=1;i<=n;i++)
        a[i]=lower_bound(b+1,b+1+len,a[i])-b;//lower_bound O(log n)for O(n) 
		printf("%d\n",len);
		for(int i=1; i<=n; i++) printf("%d ",a[i]);
		S.clear();
		printf("\n");
	} 
    return 0;
}