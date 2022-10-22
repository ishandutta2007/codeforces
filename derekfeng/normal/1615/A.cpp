#include<bits/stdc++.h>
using namespace std;
int T,n;
int main(){
	scanf("%d",&T);
	while(T--){
		int S=0;
		scanf("%d",&n);
		for(int i=0,x;i<n;i++)scanf("%d",&x),S+=x;
		puts(S%n==0?"0":"1");
	}
}