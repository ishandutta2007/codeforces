#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=60;
int T,n,c[N];
void solve(){
	scanf("%d",&n);
	for(int i=0;i<30;i++)c[i]=0;
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		for(int j=0;j<30;j++)c[j]+=x>>j&1;
	}
	for(int i=29;~i;i--)if(c[i]&1){
		puts((c[i]>>1&1)&&(~(n-c[i])&1)?"LOSE":"WIN");
		return;
	}
	puts("DRAW");
}
int main(){
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}