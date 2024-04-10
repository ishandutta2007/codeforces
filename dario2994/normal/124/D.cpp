#include <iostream>
#include <vector>
#include <algorithm>
typedef long long LL;
using namespace std;

LL su(LL x,LL m){
	LL res=(LL(x/m))*m;
	if(res<x)res+=m;
	return res;
}

LL giu(LL x,LL m){
	LL res=(LL(x/m))*m;
	if(res>x)res-=m;
	return res;
}

LL quanti(LL x, LL y){
	if(x>y) return 0;
	return y-x+1;
}

int main(){
	LL a,b,x1,y1,x2,y2;
	cin >> a >> b >> x1 >> y1 >> x2 >> y2;
	LL s1=x1+y1;
	LL s2=x2+y2;
	if(s1>s2){
		LL z=s1;
		s1=s2;
		s2=z;
	}
	//cout << su(s1,2*a) << " " << giu(s2,2*a) ;
	LL n1=su(s1,2*a)/(2*a);
	LL n2=giu(s2,2*a)/(2*a);
	//cout << n1 << " " << n2;
	LL h=quanti(n1,n2);
	//cout << h;
	
	s1=x1-y1;
	s2=x2-y2;
	if(s1>s2){
		LL z=s1;
		s1=s2;
		s2=z;
	}
	n1=su(s1,2*b)/(2*b);
	n2=giu(s2,2*b)/(2*b);
	//cout << n1 << " " << n2;
	LL k=quanti(n1,n2);
	cout <<  max(k,h);
}