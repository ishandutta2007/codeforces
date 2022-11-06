#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<class T>
void read(T &x){
	x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}
int a[200005];
int main(){
	int T;
	scanf("%d",&T);
	int n,x,j,k,i; 
	bool flg;
	while(T--){
		scanf("%d",&n);
		flg=0;
		for(i=1;i<=n;++i){
			scanf("%d",&a[i]);
			if(a[i]==1)flg=1;
		}
		sort(a+1,a+1+n);
		if(!flg){
			puts("YES");
			continue;
		}
		bool t=1;
		for(i=1;i<n;++i){
			if(a[i]==a[i+1]-1)t=0;
		}
		if(!t)puts("NO");
		else puts("YES");
	}
	return 0;
}