#include<cstdio>
#include<cstring>
#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define LL long long
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
using namespace std;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
int n,x,t;
char a[666];
int main(){
	scanf("%d",&n);
	FOR(i,1,n){
		scanf("%d%s",&x,a);
		if (t==0 && a[0]!='S' || t==20000 && a[0]!='N') return puts("NO"),0;
		if (a[0]=='S'){
			if ((t+x)>20000) return puts("NO"),0;
			else t+=x;
		}
		if (a[0]=='N'){
			if (t-x<0) return puts("NO"),0;
			else t-=x;
		}
	}
	if (t==0) puts("YES");
	else puts("NO");
	return 0;
}