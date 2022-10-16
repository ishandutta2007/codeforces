#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define int long long
using namespace std;
int n,p;
inline int lowbit(int x){
	return x&(-x);
}
inline int work(register int x){
	if (x<=0)return 1e18;
	register int ans=0;
	while(x)x-=lowbit(x),ans++;
	return ans;
}
signed main(){
	cin>>n>>p;
	for (register int i=1;i<=1e7;i++){
		if (work(n-p*i)<=i&&(n-p*i)>=i){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}