#include <iostream>
using namespace std;
int maxm(int a, int b){
	return a>b?a:b;
}
int minm(int a, int b){
	return a<b?a:b;
}
int main() {
	// your code goes here
	
	static int n,m[370],f[370];
	
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
	char g;
	int p,q;
	cin>>g>>p>>q;
	
	if(g=='M'){
		for(int j=p;j<=q;j++)
		m[j]++;
	}else{
		for(int j=p;j<=q;j++)
		f[j]++;
	}
	}
	int max =0;
	for(int i=0;i<370;i++)
	max = maxm(max,minm(m[i],f[i]));

	cout<<2*max;
	return 0;
}