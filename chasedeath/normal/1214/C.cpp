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

const int N=2e5+10,P=1e9+7;

int n,c;
char s[N],t[N];
int mi[N];



bool Check() {
	int c=0;
	rep(i,1,n) {
		if(t[i]=='(') c++;
		else c--;
		if(c<0) return 0;
	}
	return 1;
}





int main(){
	n=rd();scanf("%s",s+1);
	rep(i,1,n) if(s[i]=='(') c++;
	else c--;
	if(c) return puts("No"),0;
	int ans=0;
	drep(i,n,1) if(s[i]=='(') {
		int cnt=1;
		t[1]=s[i];
		rep(j,1,n) if(i!=j) t[++cnt]=s[j];
		ans|=Check();
		break;
	}
	rep(i,1,n) if(s[i]==')') {
		int cnt=0;
		rep(j,1,n) if(i!=j) t[++cnt]=s[j];
		t[n]=s[i];
		ans|=Check();
		break;
	}
	puts(ans?"Yes":"No");
}