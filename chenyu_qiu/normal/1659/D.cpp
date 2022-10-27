#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#define maxn 200020
#define ll long long
using namespace std;
inline int getint(){
    char c=getchar();int x=0;bool p=0;
    while((c>'9'||c<'0')&&c!='-')c=getchar();
    if(c=='-')p=1,c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    if(p)x=-x;return x;
}
int n,tr[maxn],a[maxn],ans[maxn];
int lowbit(int x){
	return x&(-x);
}
void add(int p,int x){
	for(int i=p;i<=n+1;i+=lowbit(i))tr[i]+=x;
}
int sum(int p){
	int ans=0;
	for(int i=p;i;i-=lowbit(i))ans+=tr[i];
	return ans;
}
int main(){
	int t=getint();
	while(t--){
		n=getint();
		for(int i=0;i<=n+1;++i)tr[i]=0;
		ll tmp=0;
		for(int i=1;i<=n;++i)a[i]=getint(),tmp+=a[i];
		tmp/=n;
		for(int i=n;i;--i){
			if(a[i]==i+sum(i))ans[i]=1;
			else ans[i]=0;
			add(i-tmp+1,1);
			add(i+1,-1);
			if(ans[i])--tmp;
		}
		for(int i=1;i<=n;++i){
			printf("%d",ans[i]);
			if(i<n)putchar(' ');
			else puts("");
		}
	}
	return 0;
}