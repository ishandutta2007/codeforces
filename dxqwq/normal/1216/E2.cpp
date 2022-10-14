#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;++i)
#define Max(x,y) if(x<y){x=y;}
#define Min(x,y) if(x>y){x=y;}
#define pb push_back
#define Ford(i,a,b) for(int i=a;i>=b;--i)
 
using namespace std;
 
long long Calc(int x){
	int temp = 1;
	long long sum = 0;
	while(temp<=x){
		sum += (1ll*(x-temp+1)*(x-temp+2))/2;
		temp*=10;
	}
	return sum;
}
long long Calc2(int x){
	int temp = 1;
	long long sum = 0;
	while(temp<=x){
		sum += x-temp+1;
		temp*=10;
	}
	return sum;
}
void Find(int x, int y){
	For(i,1,y){
		x/=10;
	}
	cout << x%10 << '\n';
}
void Handle(long long y){
	int l = 0;
	int r = 500000000;
	while(r-l>1){
		int mid = (l+r)>>1;
		if(Calc(mid)>=y) r = mid;
		else l = mid;
	}
	int l2 = 0;
	int r2 = r+1;
	long long temp = y-Calc(l);
	while(r2-l2>1){
		int mid = (l2+r2)>>1;
		if(Calc2(mid)>=temp) r2 = mid;
		else l2 = mid;
	}
	Find(r2,Calc2(r2)-temp);
}
int main(){
	int Q;cin >> Q;
	while(Q--)
	{
		long long y;cin >> y;
		Handle(y);
	}
	return 0;
	//dsahfjhkgsdabfsdhkbfakhfd
}