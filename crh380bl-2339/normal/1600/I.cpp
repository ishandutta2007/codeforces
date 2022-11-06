#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,k) for(int i=(j),end_i=(k);i<=end_i;i++)
#define fd(i,j,k) for(int i=(j),end_i=(k);i>=end_i;i--)
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
int main(){
	int n;
	double p;
	long long q;
	scanf("%d%lf",&n,&p);
	for(int i=0;i<=n;++i){
		q=2LL*i*(i-1)*(i-2)+6LL*i*(i-1)*(n-i)+3LL*i*(n-i)*(n-i-1);
		if(0.5*q>=p*n*(n-1)*(n-2)){
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}