#include<bits/stdc++.h>
#define QWQ int T=read(); while(T--)
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
bool a[1003];
int main()
{
	QWQ
	{
		int n=read(),m=read();
        for(int i=0; i<=1000; i++) a[i]=0;
		while(n--) a[read()]=1;
        while(m--) 
        {
            int t=read();
            if(a[t]) 
            {
                if(!a[0]) {puts("YES");
                printf("1 %d\n",t);}
                a[0]=1;
            }
        }
        if(!a[0]) puts("NO");
	}
	return 0;
}