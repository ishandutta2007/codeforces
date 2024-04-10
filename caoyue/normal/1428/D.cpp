#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<time.h>
#include<bitset>
#include<cstdio>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=1e5+7;
const int INF=1e9+7;
int n,cnt=0;
int a[N],dw[N];
struct pt{int x,y;}p[N*2];
vector<int>w1,w2;

int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%d",&a[i]);
	int l=1,r=n;
	for(int i=n;i;i--){
		if(!a[i])continue;
		if(a[i]==1){
			w1.push_back(l);
			dw[l]=i;
			p[++cnt]=(pt){i,l};
			l++;
		}
		if(a[i]==2){
			if(!w1.size()){
				puts("-1");
				return 0;
			}
			int o=w1[w1.size()-1];
			w1.pop_back();
			p[++cnt]=(pt){i,o};
			w2.push_back(i);
		}
		if(a[i]==3){
			p[++cnt]=(pt){i,l};
			if(!w2.size()){
				if(!w1.size()){
					puts("-1");
					return 0;
				}
				int o=dw[w1[w1.size()-1]];
				p[++cnt]=(pt){o,l};
				w1.pop_back();
			}
			else{
				int o=w2[w2.size()-1];
				p[++cnt]=(pt){o,l};
				w2.pop_back();
			}
			w2.push_back(i);
			l++;
		}
	}
	printf("%d\n",cnt);
	rep(i,cnt)printf("%d %d\n",n-p[i].y+1,p[i].x);
	return 0;
}