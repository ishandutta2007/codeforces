#include<bits/stdc++.h>
const int N=200050;
using namespace std;

char s[N],q[N];
int n,t,m;

void solve(){
	for(int i=n-1,j=m-1;i>=0;i--){
		if(s[i]==q[j])j--;
		else i--;
		if(j<0){printf("YES\n");return;}
	}printf("NO\n"); 
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%s%s",s,q),n=strlen(s),m=strlen(q);
		solve();
	}
}