#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;
typedef long long LL;

int main(){
	int n,m;
	cin >> n >> m;
	int t=max(n,m)+1;
	int res=0;
	for(int a=0;a<t;a++)for(int b=0;b<t;b++){
		if(a*a+b==n and a+b*b==m)res++;
	}
	cout << res;
}