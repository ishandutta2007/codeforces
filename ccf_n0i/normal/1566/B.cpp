#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define rep0(i,n) for ((i)=0;(i)<(n);(i)++)
using namespace std;
string st;
int s,i;
void solve(){
	cin>>st;
	s=0;
	int lst=1;
	rep0(i,st.size()){
		if(st[i]=='1'){
			s+=!lst;
		}
		lst=st[i]-'0';
	}
	s+=!lst;
	printf("%d\n",min(s,2));
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}