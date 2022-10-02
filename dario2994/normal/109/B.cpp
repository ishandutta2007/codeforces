#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;
typedef long long LL;

vector <LL> lucky;

double prob(LL x1,LL x2, LL y1, LL y2){//quanto  l'intersezione?
	LL i=max(x1,y1);
	LL f=min(x2,y2);
	if(f<i)return 0;
	return double(f-i+1)/double(y2-y1+1);
}

void genLuck(){
	lucky.push_back(0);
	lucky.push_back(4);
	lucky.push_back(7);
	int u=0;
	int v=2;
	for(int t=2;t<10;t++){
		for(int i=u+1;i<v+1;i++){
			lucky.push_back(lucky[i]*10+4);
			lucky.push_back(lucky[i]*10+7);
		}
		u=v;
		v=2*u+2;
	}
	lucky.push_back(1000000001);
}

int main(){
	LL a1,a2,b1,b2,k;
	genLuck();
	//cout << prob(12,45,1000,1003);
	cin >> a1 >> a2 >> b1 >> b2 >>k;
	cout.precision(100);
	double res=0;
	for(int i=0;i+k+1<int(lucky.size());i++){
		int u1=lucky[i]+1;
		int u2=lucky[i+1];
		int v1=lucky[i+k];
		int v2=lucky[i+k+1]-1;
		res+=prob(u1,u2,a1,a2)*prob(v1,v2,b1,b2);
		res+=prob(v1,v2,a1,a2)*prob(u1,u2,b1,b2);
		//cout << prob(u1,u2,a1,a2) << endl;
		//cout << u1 << " " << u2 << " " << v1 << " " << v2 << endl;
		if(k==1)res-=prob(u2,u2,a1,a2)*prob(v1,v1,b1,b2);
	}
	
	cout << res;
}