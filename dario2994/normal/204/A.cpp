#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#define INF 2000000000
#define MAXN 5010
typedef unsigned long long ULL;
typedef long long LL;
using namespace std;

LL calcola(LL r){
	if(r<=9) return r;
	if(r<=99)return 9+(r/11);
	LL b=r%10;
	LL pot=1;
	while(pot<r and pot*10<=r)pot*=10;
	LL a=int(r/pot);
	LL m=(r-a*pot)/10;
	//cout << a << " " << m << " " << b << " : " << pot << endl ;
	LL ris=9;
	ris+=LL(pot/10)-1;
	ris+=(a-1)*(pot/10);
	ris+=m;
	if(b>=a)ris++;
	return ris;
}

int main(){
	//~ int x;
	//~ cin >> x;
	//~ cout << calcola(x);
	LL l,r;
	cin >> l >> r;
	cout << calcola(r)-calcola(l-1);
}