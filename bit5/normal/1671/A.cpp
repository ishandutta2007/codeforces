#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
char str[55];
inline void work(){
	scanf("%s",str+1);
	int n=strlen(str+1);
	for(int l=1,r=0;l<=n;l=r+1){
		while(r<n && str[r+1]==str[l])r++;
		if(r-l+1==1){puts("NO");return;}
	}
	puts("YES");
}
int main(){
	int test=read();
	while(test--)work();
	return 0;
}