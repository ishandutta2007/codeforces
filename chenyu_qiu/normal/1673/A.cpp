#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#define ll long long
using namespace std;
inline int getint(){
    char c=getchar();int x=0;bool p=0;
    while((c>'9'||c<'0')&&c!='-')c=getchar();
    if(c=='-')p=1,c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    if(p)x=-x;return x;
}
#define maxn 200020
char s[maxn];
int main(){
	int t=getint();
	while(t--){
		scanf("%s",s+1);
		int n=strlen(s+1);
		int a=0,b=0;
		for(int i=1;i<=n;++i)a+=s[i]-'a'+1;
		if(n&1)b=min(s[1],s[n])-'a'+1,a-=b;
		if(a>b)printf("Alice %d\n",a-b);
		else printf("Bob %d\n",b-a);
	}
	return 0;
}