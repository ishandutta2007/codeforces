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

int main()
{
	int T=1;
	while(T--)
	{
		int n=read();
		int a=0,b=0,c=0,a1=0,b1=0,a2=0,b2=0,a3=0,b3=0;
		char ch[13];
		for(int i=1; i<=n; i++) 
		{
			scanf("%s",ch);
			if(strlen(ch)==4) if(ch[3]=='S') ++a3;
			else ++b3;
			else if(strlen(ch)==3) if(ch[2]=='S') ++a2;
			else ++b2;
			else if(strlen(ch)==2) if(ch[1]=='S') ++a1;
			else ++b1;
			else if(ch[0]=='S') ++a;
			else if(ch[0]=='M') ++b;
			else ++c;
		}
		for(int i=1; i<=n; i++) 
		{
			scanf("%s",ch);
			if(strlen(ch)==4) if(ch[3]=='S') --a3;
			else --b3;
			else if(strlen(ch)==3) if(ch[2]=='S') --a2;
			else --b2;
			else if(strlen(ch)==2) if(ch[1]=='S') --a1;
			else --b1;
			else if(ch[0]=='S') --a;
			else if(ch[0]=='M') --b;
			else --c;
		}
		int ans=abs(a3)+abs(a2)+abs(a1)+max(max(abs(a),abs(b)),abs(c));
		printf("%d\n",ans);
	}
	return 0;
}