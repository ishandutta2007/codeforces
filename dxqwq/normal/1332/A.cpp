#include<bits/stdc++.h>
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
int main()
{
	int T=read();
	while(T--)
	{
		int a=read(),b=read(),c=read(),d=read();
		int n=read(),m=read(),o=read(),p=read(),q=read(),r=read();
		if((a||b) && n==o && o==q) 
		{
			cout<<"No"<<endl;
			continue;
		 } 
		 if((c||d) && m==p && p==r) 
		{
			cout<<"No"<<endl;
			continue;
		 } 
		if(a>b) if(a-b>n-o)
		{
			cout<<"No"<<endl;
			continue;
		 }  else c=c;
		else if(b-a>q-n) 
		{
			cout<<"No"<<endl;
			continue;
		}
		if(c>d) if(c-d>m-p)
		{
			cout<<"No"<<endl;
			continue;
		} else c=c;
		else if(d-c>r-m)
		{
			cout<<"No"<<endl;
			continue;
		}
		cout<<"Yes"<<endl;
	}
	return 0;
}