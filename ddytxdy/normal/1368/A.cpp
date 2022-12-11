#include<bits/stdc++.h>
using namespace std;
int T,a,b,n;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&a,&b,&n);
		for(int i=1;;i++){
			if(a>b)swap(a,b);
			a+=b;if(a>n){printf("%d\n",i);break;}
		}
	}
	return 0;
}