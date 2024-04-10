#include<cstdio>
#include<cstring>
#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<string>
#include<cmath>
#include<algorithm>
#include<complex>
#include<vector>
#include<set>
#include<map>
#include<queue>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define LL long long
#define FOR(i,a,b) for (int i=a;i<=b;++i)
#define FORD(i,a,b) for (int i=a;i>=b;--i)
using namespace std;
typedef pair<int,int> pa;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
int n,m,q,x,y,bl,fa[500010];
int getf(int x){
	return fa[x]==x?x:fa[x]=getf(fa[x]);
}
int main(){
	cin>>n>>m>>q;
	bl=n+m-1;
	FOR(i,1,n+m) fa[i]=i;
	while (q--){
		getint(x),getint(y);
		int X=getf(y+n),Y=getf(x);
		if (X!=Y) fa[X]=Y,--bl;
	}
	cout<<bl<<endl;
    return 0;
}