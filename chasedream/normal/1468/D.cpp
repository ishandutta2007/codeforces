#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int T,a[N],n,m,A,B;
int Solve(){
	n=read(),m=read(),A=read(),B=read();
	for(int i=1;i<=m;++i){
		a[i]=read();
	}
	sort(a+1,a+m+1);
	if(A<B){
		B=B-A-1;
		--A;
	}
	else{
		B=A-B-1,A=n-A;
	}
	int ans=0;
	for(int i=m;i>=1&&B;--i){
		while(i>=1&&a[i]>A+B)--i;
		if(i>=1)++ans,--B;
	}
	return ans;
}
int main(){
	T=read();
	while(T--){
		printf("%d\n",Solve());
	}
	return 0;
}