#include<bits/stdc++.h>
//#define int long long
//const int N=
using namespace std;
int n,k;
int add(int x,int v,int ty){
	int ans=0,nw=1;
	while(x||v){
		int p=x%k,q=v%k;
		int z=(p+ty*q+k)%k;
		ans+=nw*z;
		nw*=k,x/=k,v/=k;
	}
	return ans;
}
void solve(){
	cin>>n>>k;
	cout<<0<<endl;
	int x,p=0,s=0;
	cin>>x;
	while(!x){
		p++;
		int nw=((p&1)?add(s,p,-1):add(p,s,-1));
		cout<<nw<<endl,cin>>x;
		s=(p&1)?add(s,nw,-1):add(s,nw,1);	
	}
}

int main(){
	ios::sync_with_stdio(false);
	int T=1;cin>>T;
	while(T--)solve();
}