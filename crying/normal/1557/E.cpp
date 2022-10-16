#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
int T,x,y;
string steps;
string place(int i,int j){
	x=i;y=j;
	printf("%d %d\n",x,y);
	fflush(stdout);
	string tmp;
	cin>>tmp; 
	return tmp;
}
int solve(int row){
	if(y==8){
		per(i,7,1){
			steps=place(row,i);
			if(steps=="Done")return 1;
			if(steps=="Down" || steps=="Down-Right" || steps=="Down-Left"){
				return 0;
			}
			if(steps=="Up" || steps=="Up-Right" || steps=="Up-Left"){
				if(solve(row))return 1;
				return 0;
			}
		}
		return 0;
	}
	rep(i,((y==1)?2:1),8){
		steps=place(row,i);
		if(steps=="Done")return 1;
		if(steps=="Down" || steps=="Down-Right" || steps=="Down-Left"){
			return 0;
		}
		if(steps=="Up" || steps=="Up-Right" || steps=="Up-Left"){
			if(solve(row))return 1;
			return 0;
		}
	}
	return 0;
} 
int main(){
	scanf("%d",&T);
	while(T--){
		y=1;
		rep(i,1,8){
			steps=place(i,y);
			if(steps=="Done")break;
			if(solve(i))break;
		}
		fflush(stdout);
	}

	return 0;
}