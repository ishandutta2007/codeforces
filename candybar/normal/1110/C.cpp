#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int q;
int calc1(int x){
	for(int i = 2;i * i <= x;i++){
		if(x % i == 0) return x / i;
	}
	return 1;
}
vector <P> lis;
int main(){
	for(int i = 2;i <= (1 << 26);i <<= 1){
		lis.push_back(mp(i - 1,calc1(i - 1)));
	}
	scanf("%d",&q);
	while(q--){
		int a;
		scanf("%d",&a);
		P p = *lower_bound(lis.begin(),lis.end(),mp(a,0));
		if(p.first == a) printf("%d\n",p.second);
		else printf("%d\n",p.first);
	}
	return 0;
}