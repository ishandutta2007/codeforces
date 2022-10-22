#include<bits/stdc++.h>
using namespace std;
int main(){
	int x,y,z; scanf("%d%d%d",&x,&y,&z);
	if(x+z<y) puts("-");
	else if(y+z<x) puts("+");
	else if(x==y&&z==0) puts("0");
	else puts("?");
	return 0;
}