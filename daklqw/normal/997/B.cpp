#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL unsigned long long
LL n, table[12]={
0,
4,
10,
20,
35,
56,
83,
116,
155,
198,
244,
292
};

int main() {
	cin>>n;
	//for(n=1;n<=20;++n)
		if(n<=11)cout<<table[n]<<endl;
		else cout<<292+49*(n-11)<<endl;
	return 0;
}