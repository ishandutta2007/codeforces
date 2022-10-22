#include<cstdio>
int m,a,s;
int main(){
	scanf("%d",&m);
	for(;m--;)scanf("%d",&a),s|=a;
	puts(s?"hard":"easy");
	return 0;
}