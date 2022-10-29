#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=2e5+7;
int n,a[N];
inline void work(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	int cnt=0;
	for(int i=1;i<n;i++){
		int d=a[i+1]-a[i];
		if(d>3){puts("NO");return;}
		else cnt+=d-1;
	}
	puts(cnt>2?"NO":"YES");
}
int main(){
	int test=read();
	while(test--)work();
	return 0;
}