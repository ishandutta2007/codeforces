#include<bits/stdc++.h>
using namespace std;
int n;char s[200004];
int bit[3][400004],B;
void upd(int p,int i){
	for(;i<=B+B;i+=i&-i)bit[p][i]++;
}
int qry(int p,int i){
	int ret=0;
	for(;i;i-=i&-i)ret+=bit[p][i];
	return ret;
}
void sol(){
	long long ans=0;
	scanf("%d%s",&n,s+1);
	B=n+1;
	for(int i=0;i<3;i++)memset(bit[i],0,B<<3);
	int pre=0;
	upd(0,B);
	for(int i=1;i<=n;i++){
		pre+=s[i]=='-'?1:-1;
		int p=(pre%3+3)%3;
		ans+=qry(p,pre+B),upd(p,pre+B);
	}
	printf("%lld\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)sol();
}