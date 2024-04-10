#import<bits/stdc++.h>
int k,n,i,s,t,a[33],b[33];
main(){
	for(std::cin>>t;t--;){
		std::cin>>n>>k;for(i=0;i++<n;)std::cin>>a[i];for(i=0;i++<n;)std::cin>>b[i];
		std::sort(a,a+n+1),std::sort(b,b+n+1);
		for(i=0;i++<k;)if(a[i]<b[n-i+1])a[i]=b[n-i+1];
		for(i=s=0;i++<n;)s+=a[i];std::cout<<s<<'\n';
	}
}