#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int t,a,b,c,n,k;
signed main(){
	t=1;
	while(t--){
		cin>>n>>k;
		a=2*n,b=5*n,c=8*n;
		cout<<(a-1)/k+1+(b-1)/k+1+(c-1)/k+1<<endl;
	}
	return 0;
}