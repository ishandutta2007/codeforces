#include<bits/stdc++.h>
using namespace std;
int main(){
	int T,n;cin>>T;while(T--){cin>>n;int ans;
		for(int i=2;i<31;i++){
			int x=pow(2,i)-1;
			if(n%x==0)ans=n/x;
		}cout<<ans<<endl;
	}
}