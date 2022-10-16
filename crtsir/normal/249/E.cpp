#include<bits/stdc++.h>
using namespace std;
const long long mod=10000000000;
int T;
__int128 calcc(__int128 x){
	return x*(x+1)*(2*x+1)/6;
}
__int128 calc(int _x,int _y){
	__int128 x=_x,y=_y;
	if(x==0||y==0)return 0;
	__int128 sm=min(x,y),ret=sm*sm*(sm*sm+1)/2;
	if(x<y){
		ret+=(x*(x+1)/2)*(y-x);
		ret+=x*(calcc(y-1)-calcc(x-1));
	}else{
		ret-=(y*(y-1)/2)*(x-y);
		ret+=y*(calcc(x)-calcc(y));
	}
	return ret;
}
int main(){
	cin>>T;
	while(T--){
		int xa,xb,ya,yb;
		cin>>xa>>ya>>xb>>yb;
		__int128 ans=calc(xb,yb)-calc(xa-1,yb)-calc(xb,ya-1)+calc(xa-1,ya-1);
		if(ans<=mod)
			cout<<(long long)(ans)<<endl;
		else{
			long long ret=ans%mod;
			printf("...%010lld\n",ret);
		}
	}
}