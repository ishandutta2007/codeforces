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
	int T,n,m,k,A,B;
	read(T);
	while(T--){
		read(n);read(m);read(k);
		if(n&1){
			A=m/2;
		}
		else A=0;
		if(m&1){
			B=(n*m-n)/2;
		}
		else B=n*m/2;
		if((k-A)%2||k<A||k>B)puts("no");
		else puts("yes");
	} 
	return 0;
}