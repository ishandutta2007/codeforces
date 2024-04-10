#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;
int l,r;
int main(){
	scanf("%d%d",&l,&r);
	printf("%d\n",l==r?l:2);
	return 0;
}