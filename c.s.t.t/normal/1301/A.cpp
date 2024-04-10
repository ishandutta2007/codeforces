#include<bits/stdc++.h>
using namespace std;
int T,n;
char a[110],b[110],c[110];
bool ok;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s%s%s",a,b,c),n=strlen(a),ok=true;
		for(int i=0;i<n;i++)ok&=(a[i]==c[i]||b[i]==c[i]);
		puts(ok?"YES":"NO");
	}
	return 0;
}