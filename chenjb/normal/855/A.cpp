#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define N 105
using namespace std;
char s[N][N];int n;
bool cmp(int x,int y){
	int k=strlen(s[x]+1);
	if(k!=strlen(s[y]+1))return 0;
	rep(i,k)if(s[x][i]!=s[y][i])return 0;
	return 1;
}
int main(){
	scanf("%d",&n);
	rep(i,n){
		scanf("%s",s[i]+1);
		bool q=0;
		rep(j,i-1)if(cmp(i,j)){q=1;break;}
		puts(q?"YES":"NO");
	}
	return 0;
}