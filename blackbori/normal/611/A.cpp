#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

string s;

int main()
{
	int n;
	scanf("%d",&n);
	
	cin>>s>>s;
	
	if(s=="week"){
		if(n==5 || n==6) printf("53\n");
		else printf("52\n");
	}
	if(s=="month"){
		if(n<30) printf("12\n");
		else if(n==30) printf("11\n");
		else printf("7\n");
	}
	
	return 0;
}