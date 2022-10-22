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
const int N=107;
const int INF=1e9+7;
int Get(){
	int x; scanf("%d",&x);
	return x;
}
void Fill(int x,int y,int c){
	printf("%d %d %d\n",c,x,y);
	fflush(stdout);
}
int n;
struct pt{int x,y;};
vector<pt>p1,p2;

int main(){
	scanf("%d",&n);
	rep(i,n){
		rep(j,n){
			if((i+j)&1)p1.push_back((pt){i,j});
			else p2.push_back((pt){i,j});
		}
	}
	rep(i,n*n){
		int x=Get();
		if(!p1.size()||!p2.size()){
			if(!p1.size()){
				if(x==2)Fill(p2[p2.size()-1].x,p2[p2.size()-1].y,3);
				else Fill(p2[p2.size()-1].x,p2[p2.size()-1].y,2);
				p2.pop_back(); 
			}
			else{
				if(x==1)Fill(p1[p1.size()-1].x,p1[p1.size()-1].y,3);
				else Fill(p1[p1.size()-1].x,p1[p1.size()-1].y,1);
				p1.pop_back();
			}
		}
		else{
			if(x!=1){
				Fill(p1[p1.size()-1].x,p1[p1.size()-1].y,1);
				p1.pop_back();
			}
			else{
				Fill(p2[p2.size()-1].x,p2[p2.size()-1].y,2);
				p2.pop_back();
			}
		}
	}
	return 0;
}