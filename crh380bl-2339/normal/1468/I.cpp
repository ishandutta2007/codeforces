#include<bits/stdc++.h>
#define ll long long
ll M1,M2;
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
bool chk(ll a,ll b){
	return (a>=0)&(a<b);
}
int main(){
	ll a,b,c,d,det,n,x,y;
	scanf("%lld%lld%lld%lld%lld",&n,&a,&b,&c,&d);
	M1=min(min(0LL,a),min(c,a+c));
	M2=max(max(0LL,a),max(c,a+c));
	det=a*d-b*c;
	if(abs(det)!=n){
		puts("NO");
		return 0;
	}
	if(det<0){
		swap(a,c);
		swap(b,d);
		det=-det;
	}
	puts("YES");
	for(x=M1;x<=M2;++x){
		ll A,B,C,D;
		if(c<=0){
			A=-d*x;B=det-d*x-1;
		}
		else{
			A=d*x-det+1;
			B=d*x;
		}
		if(a>=0){
			C=b*x;
			D=det+b*x-1;
		}
		else{
			C=1-det-b*x;
			D=-b*x;
		}
		if(c){
			ll t=abs(c);
			for(y=A/t-3;y*t<=B;++y){
				if(chk(a*y-b*x,det)&chk(d*x-c*y,det)){
					printf("%lld %lld\n",x,y);
				}
			}
		}
		else{
			ll t=abs(a);
			for(y=C/t-3;y*t<=D;++y){
					if(chk(a*y-b*x,det)&chk(d*x-c*y,det)){
					printf("%lld %lld\n",x,y);
				}
			}
		}
	}
	return 0;
}