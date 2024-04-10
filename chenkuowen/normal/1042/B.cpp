#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char s[10];
int f[8];
const int INF=2147483647;
int main(){
	int n; scanf("%d",&n);
	for(int i=0;i<8;++i) f[i]=i==0?0:INF; 
	for(int i=1;i<=n;++i){
		int key,sta=0; scanf("%d%s",&key,s+1);
		int len=strlen(s+1);
		for(int j=1;j<=len;++j)
			sta|=1<<s[j]-'A';
		for(int j=0;j<8;++j){
			for(int k=0;k<8;++k)
				if(f[k]<INF&&(k|sta)==j)
					f[j]=min(f[j],f[k]+key);
		}
	}
	printf("%d\n",f[7]<INF?f[7]:-1);
	return 0;
}