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

const int N=2e5+10;

int n;
char a[N];
int s,c;
int main(){
	n=rd();scanf("%s",a+1);
	rep(i,1,n/2) if(isdigit(a[i])) s+=a[i]-'0';
	else c++;
	rep(i,n/2+1,n) if(isdigit(a[i])) s-=a[i]-'0';
	else c--;
	if(s<0) s=-s,c=-c;
	if(c>0) return puts("Monocarp"),0;
	c=-c;
	if((c+1)/2*9>s) return puts("Monocarp"),0;
	if(c/2*9<s) return puts("Monocarp"),0;
	puts("Bicarp");
}