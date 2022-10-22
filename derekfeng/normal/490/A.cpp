#include<iostream>
main(){
	int n,y,i,b,a[4],c[4][5000];;
	std::cin>>n;
	for(i=0;i<n;i++)std::cin>>b,a[b]++,c[b][a[b]]=i+1;y=std::min(a[1],std::min(a[2],a[3]));
	std::cout<<y<<"\n";for(i=1;i<=y;i++)std::cout<<c[1][i]<<" "<<c[2][i]<<" "<<c[3][i]<<"\n";
}