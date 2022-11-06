#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
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
	int T,n,k,s,t;
	scanf("%d",&T);
	while(T--){
		read(n);read(k);
		t=1;s=0;
		while(k){
			if(k&1){
				s=(s+t)%mod;
			}
			t=1LL*t*n%mod;
			k>>=1;
		}
		printf("%d\n",s);
	} 
	return 0;
}