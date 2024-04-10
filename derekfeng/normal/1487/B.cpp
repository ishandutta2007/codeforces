#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,n,K;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>K;
		if(n%2==0){
			cout<<(K-1)%n+1<<'\n';
		}else{
			K--;
			ll tms=(n+1)/2-1,mov=(n+1)/2;
			if(K%tms==0)mov=K/tms*mov;
			else mov=K/tms*mov+K%tms;
			mov++;
			cout<<(mov-1)%n+1<<'\n';
		}
	}
}