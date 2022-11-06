#include<bits/stdc++.h>
#define ll long long
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
int mx,mn;
int main(){
	int T;
	scanf("%d",&T);
	int n,x,j,k; 
	while(T--){
		scanf("%d",&n);
		mn=mx=0;
		for(int i=1;i<=n;++i){
			scanf("%d",&x);
			if(i==1){
				mn=mx=x;
				j=k=1;
			}
			else{
				if(x<mn){
					j=i;
					mn=x;
				}
				if(x>mx){
					mx=x;
					k=i;
				}
			}
		}
		if(j>k)swap(j,k);
		printf("%d %d\n",j,k);
	}
	return 0;
}