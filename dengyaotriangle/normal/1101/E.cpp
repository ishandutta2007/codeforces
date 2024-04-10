#include<bits/stdc++.h>

using namespace std;

int wm,hm;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		char op;
		int x,y;
		cin>>op>>x>>y;
		if(op=='+'){
			if(x>y)swap(x,y);
			wm=max(wm,x);
			hm=max(hm,y);
		}else{
			if(x>y) swap(x,y);
			if(x>=wm&&y>=hm){
				cout<<"YES"<<endl;
			}else{
				cout<<"NO"<<endl;
			}
		}
	}
	return 0;
}