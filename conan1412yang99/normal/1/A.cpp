#include <bits/stdc++.h>

using namespace std;

long long a,b,c,t,k;


int main (){
	cin>>a>>b>>c;
	t = a / c;
	k = b / c;
	if(a % c > 0) t += 1;
	if(b % c > 0) k += 1;
	cout<<t*k;	
}