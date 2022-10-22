#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

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


const int N=1e5+100;

int n;
double a[N];
ll s;
int cnt;

int Get(double x){
	if(x<0) {
		if((int)x==x) return (int)x;
		else return (int)x-1;
	} else return (int)x;
}


int main(){
	n=rd();
	rep(i,1,n) {
		scanf("%lf",&a[i]);
		s+=Get(a[i]);
		if(Get(a[i])<a[i])cnt++;
	}
	s=-s;
	rep(i,1,n) {
		if(s>0&&Get(a[i])<a[i]) s--,printf("%d\n",Get(a[i])+1);
		else printf("%d\n",Get(a[i]));
	}
}