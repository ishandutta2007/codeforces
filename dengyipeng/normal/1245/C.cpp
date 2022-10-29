#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
#define mo 1000000007
using namespace std;

char c,c0;
int tp;
ll f0,f1,f2;

int main(){
	f0=f1=1,tp=0;
	c=getchar();
	if (c=='w'||c=='m') tp=1;
	c0=c,c=getchar();
	while (c>='a'&&c<='z'){
		if (c=='w'||c=='m') tp=1;
		f2=(f1+(c==c0&&(c0=='u'||c0=='n'))*f0)%mo;
		f0=f1,f1=f2;
		c0=c,c=getchar();
	}
	if (tp) printf("0"); else printf("%I64d",f1);
}