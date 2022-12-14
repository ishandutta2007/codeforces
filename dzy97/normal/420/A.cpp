#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
const int mo=1e9+7;
int pow(int a,int b,int c){int ret=1;for(;b;b>>=1,a=1LL*a*a%c)if(b&1)ret=1LL*ret*a%c;return ret;}

char str[100010];
int ok[200];
int main(){
	scanf("%s", str+1);
	string s="AHIMOTUVWXY";
	for(int i = 0;i < s.size();i++) ok[s[i]]=1;
	int n=strlen(str+1);
	for(int i=1;i<=n;i++) if(!ok[str[i]]){
		printf("NO\n");
		return 0;
	}
	for(int i=1;i<=n;i++) if(str[i]!=str[n-i+1]){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	return 0;
}