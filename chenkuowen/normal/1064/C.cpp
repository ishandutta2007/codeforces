#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX_N=5+1e5;
char s[MAX_N];
int main(){
	int n; scanf("%d",&n);
	scanf("%s",s+1);
	sort(s+1,s+n+1);
	printf("%s",s+1);
	return 0;
}