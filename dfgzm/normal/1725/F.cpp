#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
const int maxn=2e5+10;
const int mod=1e9+7;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	return x*f;
}
int n,m,L[maxn],R[maxn],Ans[maxn],S[maxn],a[maxn];
int main(){
	n=read();
	for(int i=1;i<=n;i++)
		L[i]=read(),R[i]=read();
	for(int k=0;k<=30;k++){
		int tag=0,len=(1<<k),top=0;
		for(int i=1;i<=n;i++)a[++top]=L[i]%len,a[++top]=R[i]%len+1;
		sort(a+1,a+1+top);
		top=unique(a+1,a+1+top)-a-1;
		for(int i=0;i<=top;i++)S[i]=0;
		for(int i=1;i<=n;i++){
			int l=L[i]%len,r=R[i]%len;
			if(R[i]-L[i]>=len){++tag;continue;}
			if(l>r)++tag;
			l=lower_bound(a+1,a+1+top,l)-a;
			r=lower_bound(a+1,a+1+top,r+1)-a;
			++S[l],--S[r];
		}int Mx=0;
		for(int i=1;i<=top;i++)S[i]+=S[i-1];
		for(int i=0;i<=top;i++)Mx=max(Mx,S[i]);
		Ans[k]=Mx+tag;
	}m=read();
	for(int i=1,x;i<=m;i++){
		x=read();
		printf("%d\n",Ans[__lg(x&(-x))]);
	}
    return 0;
}