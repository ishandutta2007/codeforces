#include <bits/stdc++.h>
using namespace std;
int T;
typedef long long ll;
ll l,r,m,M;
int ok[1000004];
int main(){
	cin>>T;
	while(T--){
		memset(ok,0,sizeof(ok));
		cin>>l>>r>>m;
		ll M=max(1ll,m-r+l),MM=m-r+l;
		for(ll i=l;i<=r;i++){
			ll Fr=(M+i-1)/i*i;
			while(Fr<=m+r-l){
				ok[Fr-MM]=i;
//				cout<<Fr<<"\n";
				Fr+=i;
			}
		}
		for(int i=l-r;i<=r-l;i++)
			if(ok[i+r-l]>0){
			//				cout<<i<<" "<<ok[i+r-l]<<"\n";
				cout<<ok[i+r-l]<<" ";
				if(i<0){
					cout<<r<<" "<<r+i<<"\n";
				}else{
					cout<<l<<" "<<l+i<<"\n";
				}
				break;
			}
	}
}