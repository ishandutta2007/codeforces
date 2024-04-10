#include<bits/stdc++.h>
#define rep(i,a,b) for(R int i=a;i<=b;i++)
#define R register
#define endl putchar('\n')
const int N=55;
using namespace std;

char s[N];
int w[N];
int ans;

void count() {
	int w1=0,w2=0;
	rep(i,1,10) {
		if(i&1) w1+=w[i];
		else w2+=w[i];
		if(5-(i+1)/2+w1<w2) { ans=min(ans,i); break; }
		if(5-i/2+w2<w1) { ans=min(ans,i); break; }
	}
}
void check() {
	ans=10;
	rep(i,1,5) {
		if(s[2*i-1]=='?') w[2*i-1]=1;
		else w[2*i-1]=s[2*i-1]-'0';
		if(s[2*i]=='?') w[2*i]=0;
		else w[2*i]=s[2*i]-'0';
	}
	count();
	rep(i,1,5) {
		if(s[2*i-1]=='?') w[2*i-1]=0;
		else w[2*i-1]=s[2*i-1]-'0';
		if(s[2*i]=='?') w[2*i]=1;
		else w[2*i]=s[2*i]-'0';
	}
	count();
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%s",s+1);
		check();
		printf("%d\n",ans);
	}
	return 0;
}