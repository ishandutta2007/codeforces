#include<bits/stdc++.h>
main(){
	int t,n;std::cin>>t;
	while(t--){
		std::cin>>n;
		if(n&3)std::puts("NO");
		else{
			std::puts("YES");
			for(int i=1;i<=n/2;i++)std::cout<<i*2<<' ';for(int i=1;i<n/2;i++)std::cout<<i*2-1<<' ';
			std::cout<<n+n/2-1<<'\n';
		}
	}
}