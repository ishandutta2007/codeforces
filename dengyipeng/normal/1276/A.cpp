#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 200005
using namespace std;

int T,i,j,k,n,ans[maxn];
char ch,s[maxn];

int main(){
	scanf("%d",&T);
	while (T--){
		for(ch=getchar();ch<'a'||ch>'z';ch=getchar());
		n=0;
		for(;ch>='a'&&ch<='z';ch=getchar()) s[++n]=ch;
		ans[0]=0;
		for(i=3;i<=n;i++){
			if (s[i-2]=='o'&&s[i-1]=='n'&&s[i]=='e')
				ans[++ans[0]]=i-1,i+=2;
			else 
			if (s[i-2]=='t'&&s[i-1]=='w'&&s[i]=='o') {	
				if (i+2<=n&&s[i+1]=='n'&&s[i+2]=='e')
					ans[++ans[0]]=i,i+=2;
				else 
					ans[++ans[0]]=i-1,i+=2;
			}
		}
		printf("%d\n",ans[0]);
		for(i=1;i<=ans[0];i++) printf("%d ",ans[i]);
		printf("\n");
	}
}