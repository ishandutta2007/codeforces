#include<bits/stdc++.h>
using namespace std;
int T;
long long a,b,c;
void solve(){
	cin>>a>>b>>c;
	if(a*b<c){
		cout<<1<<" "<<-1<<"\n";
		return;
	}
	if(a*b==c){
		cout<<1<<" "<<-1<<"\n";
		return;
	}
	if(a<c)cout<<1;
	else cout<<-1;
	cout<<" "<<b<<"\n";
}
int main(){
	cin>>T;
	while(T--)solve();
}