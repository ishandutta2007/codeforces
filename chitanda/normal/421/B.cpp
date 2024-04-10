#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long

char s[101000];

bool ok(char ch){
	if (ch!='A' && ch!='H' && ch!='I' && ch!='M' && ch!='O' && ch!='T' &&
			ch!='U' && ch!='V' && ch!='W' && ch!='X' && ch!='Y') return 0;
	else return 1;
}

int main(){
	scanf("%s",s+1); int len=strlen(s+1);
	for(int i=1;i<=len;i++)
		if (s[i]!=s[len-i+1] || !ok(s[i])) { printf("NO"); return 0; }
	printf("YES");
	return 0;
}