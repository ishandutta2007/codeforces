#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[1000003],b[1000003];
set<int> s[4];
bool check()
{
	if(s[3].size()) return 1; 
	if(s[2].size()>1) return 1;
	if(s[2].size()&&(s[1].size()||s[0].size())) return 1;
	if(s[1].size()>1) return 1;
	if(s[1].size()&&s[0].size()>1) return 1;
	return 0;
}
int main()
{
    int n=read();
    for(int i=1; i<=n; i++) a[i]=read(),++b[a[i]];
    for(int i=1; i<=n; i++) 
	if(b[i]>=8) s[3].insert(i);
    else if(b[i]>=6) s[2].insert(i);
    else if(b[i]>=4) s[1].insert(i);
    else if(b[i]>=2) s[0].insert(i);
    int m=read();
    while(m--)
    {
    	char ch=getchar();
    	while(ch!='+' && ch!='-') ch=getchar();
    	int k=read();
    	if(ch=='+') 
		{
			if(b[k]==1) s[0].insert(k);
			if(b[k]==3) s[1].insert(k),s[0].erase(k);
			if(b[k]==5) s[2].insert(k),s[1].erase(k);
			if(b[k]==7) s[3].insert(k),s[2].erase(k);
			++b[k];
		}
		else
		{
			if(b[k]==2) s[0].erase(k);
			if(b[k]==4) s[0].insert(k),s[1].erase(k);
			if(b[k]==6) s[1].insert(k),s[2].erase(k);
			if(b[k]==8) s[2].insert(k),s[3].erase(k);
			--b[k];
		}
		if(check()) puts("YES"); else puts("NO");
	}
    return 0;
}