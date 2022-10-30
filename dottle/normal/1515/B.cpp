#include<bits/stdc++.h>
using namespace std;

int n,t;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n&1)printf("NO\n");
		else{
			while(n%2==0)n/=2;
			int p=sqrt(n);
			if(n==p*p)printf("YES\n");
			else printf("NO\n");
		}
	}
}