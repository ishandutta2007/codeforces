#include<bits/stdc++.h>
using namespace std;
int T,a,b,c,d;
bool ok;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&a,&b,&c,&d),ok=false;
		ok|=((a&1)+(b&1)+(c&1)+(d&1)<=1);
		if(a&&b&&c)a--,b--,c--,d+=3;
		ok|=((a&1)+(b&1)+(c&1)+(d&1)<=1);
		puts(ok?"Yes":"No");
	}
	return 0;
}