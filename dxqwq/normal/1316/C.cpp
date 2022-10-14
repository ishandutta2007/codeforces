#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=2139114514;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int n, m, p, x, ans1, ans2;
int main() {
    n=read(); m=read(); p=read();
    ans1=ans2=-1; 
    for (int i=1; i<=n; i ++ ) 
	{
        x=read();
        if(x % p && ans1==-1) ans1=i-1;
    }
    for (int i=1; i<=m; i++) 
	{
        x=read();
        if(x % p && ans2==-1)  ans2=i-1;
    }
    cout<<ans1+ans2;
    return 0;
}