#include<bits/stdc++.h>
using namespace std;
int n,m;
void solve(){
	int ans=0;
	cin>>n>>m;m++;
	for(int i=30;~i;i--){
		int c=(1<<i),s=(n>>i)&1;
		if(m>=c){
			if(s==0){
				ans=(ans<<1)+1;
				m-=c;
			}else{
				ans=(ans<<1)+0;
				m-=c;
			}
		}else{
			if(s==0){
				ans=(ans<<1)+0;
			}else{
				for(int j=i;~j;j--)ans<<=1;
				break;
			}
		}
	}
	cout<<ans<<"\n";
}
int main(){
	int Tc;
	for(cin>>Tc;Tc--;)solve();
}