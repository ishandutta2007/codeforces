#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define int long long
#define mod 1000000007
using namespace std;
int l,r;
inline int work(int x){
	if (x==0)return 0;
	int numa=0,numb=0,now=1;
	for (int i=1;;i++){
		if (x<=now){
			if (i%2==1)numa+=x,numa%=mod;
			else numb+=x,numb%=mod;
			break;
		}
		if (i%2==1)numa+=now,numa%=mod;
		else numb+=now,numb%=mod;
		x-=now;
		now*=2;
	}
	int sa,sb;
	sa=((numa%mod)*(numa%mod))%mod,sb=((numb%mod)*(numb%mod)%mod+numb)%mod;
	return (sa+sb)%mod;
}
signed main(){
	cin>>l>>r;
	cout<<(work(r)-work(l-1)+mod)%mod;
	return 0;
}