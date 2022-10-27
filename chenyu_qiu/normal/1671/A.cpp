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
char s[55]; 
bool check(int n){
	int cnt=0;
	for(int i=1;i<=n;++i){
		if(i>1&&s[i]!=s[i-1]){
			if(cnt<=1)return 0;
			cnt=0;
		}
		++cnt;
	}
	if(cnt<=1)return 0;
	return 1;
}
int main(){
	int t=getint();
	while(t--){
		scanf("%s",s+1);
		int n=strlen(s+1);
		if(check(n))puts("YES");
		else puts("NO");
	}
	return 0;
}