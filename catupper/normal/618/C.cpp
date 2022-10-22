#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<cstdio>
#include<cmath>
using namespace std;

typedef long long Int;
typedef pair<Int, Int> P;
typedef double Real;

set<Int> ins;
Int x[108000], y[108000], a, b, c;


Int area(Int a, Int b, Int c){
	Int x1 = x[a];
	Int y1 = y[a];
	Int x2 = x[b];
	Int y2 = y[b];
	Int x3 = x[c];
	Int y3 = y[c];
	
	x1 -= x3;
	y1 -= y3;
	x2 -= x3;
	y2 -= y3;
	
	return abs(x1 * y2 - y1 * x2);
}

Int inside(Int a, Int b, Int c, Int d){
	if(area(a, b, c) != area(a, b, d) + area(b, c, d) + area(c, a, d))return false;
	if(a == d || b == d || c == d)return false;
	return true;
}

void cut(){
	set<Int>::iterator it = ins.begin();
	Int ab = 0;
	Int bc = 0;
	Int ca = 0;
	Int d = *it;
	if(area(a, b, d) == 0)ab = 1 << 24;
	if(area(b, c, d) == 0)bc = 1 << 24;
	if(area(c, a, d) == 0)ca = 1 << 24;
	for(it++ ; it != ins.end();it++){
		if(inside(a, b, d, *it))ab++;
		if(inside(b, c, d, *it))bc++;		
		if(inside(c, a, d, *it))ca++;
	}
	Int dmin = min(ab, bc);
	dmin = min(ca, dmin);
	
	if(ab == dmin)c = d;
	else if(bc == dmin)a = d;
	else if(ca == dmin)b = d;
	for(it = ins.begin(); it != ins.end();){
		if(!inside(a, b, c, *it)){
			ins.erase(it++);
		}
		else it++;
	}	
}

int main(){  
	Int n;
	cin >> n;
	for(Int i = 0;i < n;i++)cin >> x[i] >> y[i];
	a = 0;
	b = 1;
	c = 2;
	while(area(a, b, c) == 0)c++;
	
	for(Int i = 0;i < n;i++){
		if(inside(a, b, c, i))
			ins.insert(i);
	}
	
	while(!ins.empty()){
		cut();
	}
	
	cout << a + 1 << " " << b + 1 << " " << c + 1 << endl;
	return 0;	
}