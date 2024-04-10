#include<bits/stdc++.h>
//#define int long long
//const int N=
using namespace std;

int t,a,b,c;

int main(){
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>a>>b>>c;
		if(a<b)swap(a,b);
		if((a-b)*2<c||(a-b)*2<a)cout<<-1<<endl;
		else cout<<(c+a-b-1)%((a-b)*2)+1<<endl;
	}
}