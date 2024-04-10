#include<bits/stdc++.h>
using namespace std;

#define reg register
typedef long long ll;
#define rep(i,a,b) for(reg int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(reg int i=a,i##end=b;i>=i##end;--i)

char IO;
int rd(){
	int s=0,f=0;
	while(!isdigit(IO=getchar())) if(IO=='-') f=1;
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=1e3+10;

int n;
char s[N];


int main(){
	rep(kase,1,rd()) {
		n=rd();
		scanf("%s",s+1);
		int ans=n;
		rep(i,1,n) {
			if(s[i]=='1') {
				ans=max(ans,n+1);
				ans=max(ans,i*2);
				ans=max(ans,(n-i+1)*2);
			}
		}
		printf("%d\n",ans);
	}
}