/******************
*  Writer: Oh no  *
******************/
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

int n,m,a,b,k;
int rf,rt,mf,mt;
int ans;

int ab(int x){
	return x>=0 ? x : -x ;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>a>>b>>k;
	while(k--){
		ans=0;
		cin>>rt>>rf>>mt>>mf;
		if(rt!=mt && (rf<a && mf<a)){
			ans+=a-rf;
			ans+=a-mf;
			ans+=ab(rt-mt);
		}else
		if(rt!=mt && (rf>b && mf>b)){
			ans+=rf-b;
			ans+=mf-b;
			ans+=ab(rt-mt);
		}else
		if(rt!=mt){
			ans+=ab(rf-mf);
			ans+=ab(rt-mt);
		}else
			ans+=ab(rf-mf);
		cout<<ans<<endl;
	}
	return 0;
}