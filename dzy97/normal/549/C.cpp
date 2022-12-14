#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <deque>
#include <queue>
#include <set>
#include <cstdlib>
#include <cassert>
using namespace std;
typedef long long ll;
typedef pair<int,int> PI;
typedef vector<int> VI;
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define cl(x,a) memset(x,a,sizeof(x))
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
const int mo = 1e9 + 7;
int pow(int a,int b,int c){int ret=1;for(;b;b>>=1,a=1LL*a*a%c)if(b&1)ret=1LL*ret*a%c;return ret;}
int cnt[2],n,k;
int work(){
	if(!k){
		if(cnt[1]&1) return 1; else return 0;
	}
	if(!cnt[0]){
		if((cnt[1]&1)^(k&1)) return 1; else return 0;
	}
	if(!cnt[1]) return 0;
	if(cnt[1]<=k/2) return 0;
	if(cnt[0]<=k/2&&(n-k)%2==0) return 0;
	if(cnt[0]<=(k+1)/2&&(n-k)%2==1) return 1;
	return k%2;
/*	if(~k&1){
		if(cnt[1]&1){
			if(cnt[1]<=k/2) return 0;
			if(cnt[0]%2==1&&cnt[0]<k) return 0;
			return 1;
		}else{
			if(cnt[0]%2==1) return 1; else return 0;
		}
	}else{
		if(cnt[1]&1){
			if(cnt[1]>k/2) return 1; else return 0;
		}else{
			return 1;
		}
	}*/
}
int main(){
	scanf("%d%d",&n,&k);
	k=n-k;
	int x;
	for(int i=1;i<=n;i++) scanf("%d",&x),cnt[x&1]++;
	printf("%s\n",work()?"Stannis":"Daenerys");
	return 0;
}