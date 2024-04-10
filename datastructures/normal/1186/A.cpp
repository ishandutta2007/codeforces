#include <iostream>
#include <cstdio>
using namespace std;
int n,m,k;
int main(){
	cin>>n>>m>>k;
	if (m>=n&&k>=n)puts("YES");
	else puts("NO"); 
	return 0;
}