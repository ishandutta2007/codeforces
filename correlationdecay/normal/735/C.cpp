#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#define maxn 100009
#define PS system("pause");
using namespace std;
long long f[1000];
int main(){
	long long n;
	cin>>n;
	f[1]=2;
	f[2]=3;
	for(int i=3;i<=999;i++)
		f[i]=f[i-1]+f[i-2];
	long long ans=0;
	for(int i=1;i<=999;i++){
		if(f[i]>n)
			break;
		ans=i;
	}
	cout<<ans<<endl;
	//PS;
	return 0;
}