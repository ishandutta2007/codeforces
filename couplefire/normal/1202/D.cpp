#include<bits/stdc++.h>
#define REP(i,s,t) for(int i=s;i<=t;i++)
using namespace std;
int main(){
	int T; cin>>T;
	while(T--){
		int n; cin>>n;
		int w;
		for(w=2;w*(w-1)/2<=n;w++);
		w--;
		cout<<1;
		REP(i,1,w-2) cout<<3;
		REP(i,1,n-w*(w-1)/2) cout<<1;
		cout<<"337"<<'\n';
	}
	return 0;
}