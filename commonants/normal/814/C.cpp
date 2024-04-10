#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;
const int MX=1511;
int ans[27][MX];
int n,q;
char s[MX];
int wk(char c,int m){
	if(ans[c-'a'][m]!=-1)return ans[c-'a'][m];
	else{
		int res=0;
		int l=1,tc=0;
		for(int i=1;i<=n;i++){
			tc+=(s[i]!=c);
			while(tc>m){
				tc-=(s[l++]!=c);
			}
			res=max(res,i-l+1);
		}
		return ans[c-'a'][m]=res;
	}
}
int main(){
	memset(ans,-1,sizeof(ans));
	scanf("%d",&n);
	scanf("%s",s+1);
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int m;char t[2];
		scanf("%d%s",&m,t);
		printf("%d\n",wk(t[0],m));
	}
	return 0;
}