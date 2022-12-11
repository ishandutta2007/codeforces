#include<bits/stdc++.h>
using namespace std;
int x,y,z,ret;
int cmp(int x,int y){
	if(x==y)return 0;
	if(x<y)return -1;
	return 1;
}
int main(){
	scanf("%d%d%d",&x,&y,&z);
	if(cmp(x+z,y)!=cmp(x,y+z))puts("?");
	else if(x>y)puts("+");
	else if(x<y)puts("-");
	else puts("0");
	return 0;
}