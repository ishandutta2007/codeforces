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
int n,x[maxn];
bool check(int a0){
	for(int i=1;i<=n;++i)if(abs(x[i]-a0-i)>1)return 0;
	return 1;
}
int main(){
	int t=getint();
	while(t--){
		n=getint();
		for(int i=1;i<=n;++i)x[i]=getint();
		if(check(x[1]-2)){puts("YES");continue;}
		if(check(x[1]-1)){puts("YES");continue;}
		if(check(x[1])){puts("YES");continue;}
		puts("NO");
	}
	return 0;
}