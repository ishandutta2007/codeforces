#include<bits/stdc++.h>
#define int long long
using namespace std;

int chk(int x,int y,int p){
	if(x<y)swap(x,y);
	if(x==p||y==p)return 1;
	if(x<p)return 0;
	if(y==0)return 0;
	if(x%y==p%y)return 1;
	return chk(x%y,y,p);
}

void solve(){
	int x,y,p;cin>>x>>y>>p;
	cout<<(chk(x,y,p)?"YES":"NO")<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}