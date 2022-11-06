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
const int INF=2e9+10;
int n,MI,MA,c[200010],d[200010],s,t;
int main(){
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d%d",&c[i],&d[i]),s+=c[i];
	MI=-INF;
	MA=INF;
	FOR(i,1,n){
		if (d[i]==1) MI=max(MI,1900-t);
		if (d[i]==2) MA=min(MA,1899-t);
		t+=c[i];
	}
	if (MI>MA) return puts("Impossible"),0;
	else if (MA==INF) return puts("Infinity"),0;
	else return printf("%d\n",MA+s),0;
}