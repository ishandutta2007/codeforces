#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,a,b,c,d,e,f;
int main(){
	cin>>n>>e>>f>>a>>b>>c>>d;
	if (a<e&&b<f&&c<e&&d<f)puts("YES");
	else if (a<e&&b>f&&c<e&&d>f)puts("YES");
	else if (a>e&&b<f&&c>e&&d<f)puts("YES");
	else if (a>e&&b>f&&c>e&&d>f)puts("YES");
	else puts("NO");
	return 0;
}