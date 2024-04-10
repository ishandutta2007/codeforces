#include <bits/stdc++.h> 
using namespace std;

typedef unsigned long long ll;

#define rep(a,b,c) for(int a=b,a##end=c;a<=a##end;++a)
#define drep(a,b,c) for(int a=b,a##end=c;a>=a##end;--a)

char IO;
int rd(){
	int s=0,f=0;
	while(IO=getchar(),IO<'0'||IO>'9')if(IO=='-')f=1;
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(IO=getchar(),IO>='0'&&IO<='9');
	return f?-s:s;
}


const int N=1e6+100;


char s1[N],s2[N];

int Q[N],L=1,R=0;
int ans;

int main(){
	scanf("%s%s",s1+1,s2+1);
	int l1=strlen(s1+1),l2=strlen(s2+1);
	int pre=0;
	for(int i=1;i<=l2;i++){
		if(s1[i]!=s2[i]) pre^=1;
		if(i>1&&s1[i]!=s1[i-1]) Q[++R]=i;
	}
	if(pre==0) ans++;
	rep(i,l2+1,l1){
		if(i>1&&s1[i]!=s1[i-1]) Q[++R]=i;
		while(Q[L]<=i-l2&&L<=R) L++;
		//rep(j,L,R) cout<<Q[j]<<' ';puts("");
		pre=(pre+R-L+1)&1;
		if(pre==0) ans++;
	}
	printf("%d\n",ans);
}