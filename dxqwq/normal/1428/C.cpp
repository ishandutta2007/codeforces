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
char a[1000003];
int main()
{
	int T=read();
	while(T--)
	{
		scanf("%s",a);
		int n=strlen(a);
		int ans=0,lst=0;
        for(int i=n-1; i>=0; i--) if(a[i]=='A') if(lst>0) --lst; else ++ans; else ++lst;
        ans+=(lst&1);
        printf("%d\n",ans);
    }
	return 0;
}