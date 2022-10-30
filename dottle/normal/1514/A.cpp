#include<bits/stdc++.h>
using namespace std;

int n,x,fl,t;

bool chk(int k){int p=sqrt(k);return p*p==k;}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n),fl=0;
		while(n--)scanf("%d",&x),fl|=!chk(x);
		printf("%s\n",fl?"YES":"NO");
	}
}