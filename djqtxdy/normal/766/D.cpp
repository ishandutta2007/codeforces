#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string.h>
#include <stdio.h>
#define LL long long
#define pii pair<int,int>
#define piii pair<int, pii >
#define REP(i,n) for (int (i)=0;(i)<(n);(i)++)
#define vi vector<int>
#define vpi vector< pii >
#define INF 2147483647
#define big 20160116
#define pb push_back
#define mp make_pair
using namespace std;
const int Maxn=100000;
const int Maxk=20;
map<string,int> f;
char c[Maxk+5];
int fa[Maxn*2];
void _init(){
	for (int i=0;i<Maxn*2;i++){
		fa[i]=i;
	} 
}
int fan(int x){
	if (x>=Maxn) return x-Maxn; else return x+Maxn;
}
int findset(int x){
	return fa[x]=(fa[x]==x)?x:findset(fa[x]);
}
void Union(int x,int y){
	x=findset(x);
	y=findset(y);
	if (rand()&1) 
	fa[x]=y,fa[fan(x)]=fan(y); else fa[y]=x,fa[fan(y)]=fan(x); 
}
void Union2(int x,int y){
	x=findset(x);
	y=findset(y);
	if (rand()&1) {
		fa[x]=fan(y); 
		fa[fan(x)]=y;
	} else fa[y]=fan(x),fa[fan(y)]=x;
}
int cg(int x){
	if (x==1) return 1;
	return -1;
}
int main(){
	_init();
	int n,m,q;
	scanf("%d %d %d",&n,&m,&q);
	for (int i=0;i<n;i++){
		scanf("%s",c);
		string s;
		for (int j=0;j<strlen(c);j++){
			s+=c[j];
		}
		f[s]=i+1;
	}
	for (int i=0;i<m;i++){
		int t;
		string x,y;
		scanf("%d",&t);
		scanf("%s",c);
		for (int j=0;j<strlen(c);j++){
			x+=c[j];
		}
		scanf("%s",c);
		for (int j=0;j<strlen(c);j++){
			y+=c[j];
		}
		int u=f[x],v=f[y];
		if (findset(u)==findset(v)){
			if (cg(t)==-1){
				printf("NO\n");
			}
			else{
				printf("YES\n");
			}
		}
		else if (findset(u)==fan(findset(v))){
			if (cg(t)==1){
				printf("NO\n");
			}
			else{
				printf("YES\n");
			}
		}
		else{
			printf("YES\n");
			if (t==1){
				Union(u,v);
			}
			else{
				Union2(u,v);
			}
		}
	}
	while (q--){
		string x,y;
		scanf("%s",c);
		for (int j=0;j<strlen(c);j++){
			x+=c[j];
		}
		scanf("%s",c);
		for (int j=0;j<strlen(c);j++){
			y+=c[j];
		}
		int u=f[x],v=f[y];
		if (findset(u)==findset(v)){
			printf("1\n");
		}
		else if (findset(u)==fan(findset(v))){
			printf("2\n");
		}
		else{
			printf("3\n");
		}
	}
	return 0;
}