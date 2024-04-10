#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	double h,l;
	cin>>h>>l;
	printf("%.9f\n",(pow(l,2)-pow(h,2))/(2*h));
	return 0;
}