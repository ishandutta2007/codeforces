#include<bits/stdc++.h>
using namespace std;
int main(){int T;
	cin>>T;while(T--){
		int n,cnt=0,cntt=0;cin>>n;
		for(int i=0;i<n;i++){int a;cin>>a;if(a%2==0)cnt++;else cnt--;if(a%2!=i%2)cntt++;}
		if(n%2!=cnt)cout<<-1<<endl;
		else cout<<cntt/2<<endl;
	}
}