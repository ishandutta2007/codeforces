#include<bits/stdc++.h>
#define LL long long
#define mp make_pair
#define fi first
#define se second
using namespace std;
int read(){
	char ch=getchar(); int x=0,fl=1;
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') fl=-1;
	for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch-'0');
	return x*fl;
}

int main(){
	int T=read();
	while(T--){
		int n=read(),p=0;
		for(int i=1;i<=n+n;i++){
			int x=read();
			if(x&1) p++;
		}
		if(p==n) cout<<"Yes\n"; else cout<<"No\n";
	} 
	return 0;
}