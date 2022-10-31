#include<bits/stdc++.h>
using namespace std;
#define N 5050
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
int T,n;
char s[N];
inline bool check(int dx,int dy){
	int x=0,y=0;
	for(int i=1;i<=n;++i){
		if(s[i]=='L'){
			if(dy!=y||dx!=x-1)--x;
		}
		else if(s[i]=='R'){
			if(dy!=y||dx!=x+1)++x;
		}
		else if(s[i]=='U'){
			if(dy!=y+1||dx!=x)++y;
		}
		else{
			if(dy!=y-1||dx!=x)--y;
		}
	}
	return x==0&&y==0;
}
void Solve(){
	int x=0,y=0;
	for(int i=1;i<=n;++i){
		if(s[i]=='L')--x;
		else if(s[i]=='R')++x;
		else if(s[i]=='U')++y;
		else --y;
		if((x||y)&&check(x,y)){
			printf("%d %d\n",x,y);
			return;
		}
	}
	printf("0 0\n");
}
int main(){
	T=read();
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		Solve();
	}
	return 0;
}