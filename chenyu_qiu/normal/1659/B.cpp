#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define maxn 200020
using namespace std;
inline int getint(){
    char c=getchar();int x=0;bool p=0;
    while((c>'9'||c<'0')&&c!='-')c=getchar();
    if(c=='-')p=1,c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    if(p)x=-x;return x;
}
char s[maxn];
int ans[maxn];
int main(){
	int t=getint();
	while(t--){
		int n=getint(),k=getint();
		int sum=k;
		scanf("%s",s+1);
		for(int i=1;i<n;++i){
			ans[i]=0;
			if(s[i]=='1'){
				if(k&1){
					if(sum)--sum,++ans[i];
					else s[i]=((s[i]-'0')^1)+'0';
				}
			}
			else{
				if(!(k&1)){
					if(sum)--sum,++ans[i],s[i]=((s[i]-'0')^1)+'0';
				}
				else s[i]=((s[i]-'0')^1)+'0';
			}
		}
		ans[n]=sum;
		if((k-sum)&1)s[n]=((s[n]-'0')^1)+'0';
		for(int i=1;i<=n;++i)putchar(s[i]);
		puts("");
		for(int i=1;i<=n;++i){
			printf("%d",ans[i]);
			if(i<n)putchar(' ');
			else putchar('\n');
		}
	}
	return 0;
}