#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b;scanf("%d%d",&a,&b);
	const int table[]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600};
	printf("%d\n",table[min(a,b)]);
	return 0;
}