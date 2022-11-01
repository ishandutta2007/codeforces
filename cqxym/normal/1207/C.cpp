#include<bits/stdc++.h>
using namespace std;
#define ll long long
char c[200001];
ll f1[200001],f2[100001];
void Solve(){
	int n,a,b,i,h=1;
	scanf("%d%d%d\n",&n,&a,&b);
	scanf("%s",c+1);
	c[n+1]='2';
	f1[0]=b;
	f2[0]=1e14;
	for(i=1;i<=n;i++){
		if(c[i+1]!='1'&&c[i]=='0'){
			f1[i]=min(f1[i-1],f2[i-1]+a)+a+b;
		}else{
			f1[i]=1e14;
		}
		f2[i]=min(f1[i-1]+a,f2[i-1])+a+b+b;
	}
	printf("%lld\n",f1[n]);
}
int main(){
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		Solve();
	}
	return 0;
}