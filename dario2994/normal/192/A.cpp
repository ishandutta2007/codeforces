#include <iostream>
#include <cmath>
typedef long long LL;
using namespace std;

LL tri[1000000];

bool isTri(LL x){
	if(x<=0)return false;
	if(x==1 or x==3 or x==6)return true;
	x=2*x;
	LL sq=sqrt(x);
	if(sq*(sq+1)==x)return true;
	return false;
}

int main(){
	for(LL i=1;i<100000;i++)tri[i]=(i*(i+1))/2;
	tri[100000]=-1;
	int n;
	cin >> n;
	for(int i=1;i<100000;i++){
		if(isTri(n-tri[i])){
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}