#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string s;
int n,k,p;

int main()
{
	cin>>n;

	for(;n--;){
		cin>>k>>s;
		if(s=="North") p -= k;
		else if(s=="South") p += k;
		else if(p==0 || p==20000){
			printf("NO\n");
			return 0;
		}

		if(p<0 || p>20000){
			printf("NO\n");
			return 0;
		}
	}

	if(p==0) printf("YES\n");
	else printf("NO\n");

	return 0;
}