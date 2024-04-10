#include<bits/stdc++.h> 
using namespace std;
const int illegal=1e9+7;
typedef long long LL;
int n,pr=illegal,pb=illegal,pg=illegal,mr,mb;
LL ans;
char s[10];
void input(){
	scanf("%d",&n);
}
void doBP(int x){
	if(pr!=illegal){
		ans+=x-pr;
		mr=max(mr,x-pr);
	}
	pr=x;
}
void doRP(int x){
	if(pb!=illegal){
		ans+=x-pb;
		mb=max(mb,x-pb);
	}
	pb=x;
}
void solve(){
	ans =0;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d %s",&x,s);
		if(s[0]=='B'||s[0]=='P'){
			doBP(x);
		}
		if(s[0]=='R'||s[0]=='P'){
			doRP(x);
		}
		if(s[0]=='P'){
			if(pg!=illegal)ans+=min(0,x-pg-mr-mb);
			pg=x;mr=0;mb=0;
		}
	}
	cout<<ans<<endl;
}
int main(){
	input();
	solve();
	return 0;
}