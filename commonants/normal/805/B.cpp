#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)putchar(((i>>1)&1)+'a');
	return 0;
}