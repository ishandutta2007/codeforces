#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string s;
int sum,i,j,k,x,y,n;

int main()
{
	scanf("%d",&n);
	cin>>s;
	
	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			x=0,y=0;
			for(k=i;k<=j;k++){
				if(s[k]=='U') y++;
				if(s[k]=='D') y--;
				if(s[k]=='L') x++;
				if(s[k]=='R') x--;
			}
			if(x==0 && y==0) sum++;
		}
	}
	
	printf("%d\n",sum);
	
	return 0;
}