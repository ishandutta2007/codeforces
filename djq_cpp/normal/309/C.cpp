#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <bitset>
#include <algorithm>
#include <functional>
#define rep(k,n)for(int k=0;k<n;k++)
using namespace std;
int bita[40],bitb[40];
void dealw(int a){
	int t=0;
	while(a){
		bita[t]+=a%2;
		t++;
		a/=2;
	}
}
bool toms(int &nowid){
	while(nowid<40&&bitb[nowid]==0)nowid++;
	if(nowid==40)return false;
	bitb[nowid]--;
	int mns=nowid;
	while(mns<40&&bita[mns]==0){
		bita[mns]=1;
		mns++;
	}
	if(mns==40)return false;
	bita[mns]--;
	return true;
}
int main(){
	int n,m,in,ans=0,nowid=0;
	scanf("%d%d",&n,&m);
	rep(k,n){
		scanf("%d",&in);
		dealw(in);
	}
	rep(k,m){
		scanf("%d",&in);
		if(in<40)bitb[in]++;
	}
	while(toms(nowid))ans++;
	printf("%d",ans);
	return 0;
}