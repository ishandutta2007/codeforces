#include<bits/stdc++.h>
using namespace std;
int a[3]={0,1,2};

int main()
{
	int n,x;
	cin>>n>>x;
	
	n=n%6;
	for(int i=0;i<n;i++){
		 if(i%2==0){
		 	swap(a[0],a[1]);
		 }
		 else{
		 	swap(a[1],a[2]);
		 }
	}
	cout<<a[x]<<endl;
	return 0;
}