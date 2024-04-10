#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,a;
void sol(){
	ll lst=0,now=-1;
	bool ok=1;
	for(int i=0;i<n;i++){
		cin>>a;
		if(a>now)lst+=a-(now+1);
		else{
			lst-=(now+1)-a;
			if(lst<0&&ok){
				cout<<"NO\n";
				ok=0;
			}
		}
		now++;
	}
	if(ok)cout<<"YES\n";
}
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		sol();
	}
}