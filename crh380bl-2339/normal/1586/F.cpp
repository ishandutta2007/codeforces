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
int work(int x,int y,int z){
	int s=0;
	while(x!=y){
		x/=z;
		y/=z;
		++s;
	}
	return s;
}
int main(){
	int n,k,t=1,i,j;
	read(n);read(k);
	for(i=0;t<n;++i,t*=k);
	printf("%d\n",i);
	for(i=0;i<n;++i){
		for(j=i+1;j<n;++j){
			printf("%d ",work(i,j,k));
		}
	}
	return 0;
}