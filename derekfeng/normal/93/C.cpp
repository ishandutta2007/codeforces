#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <sstream>
#include <stack>
#include <time.h>
#include <vector>
#include <complex>
#include <map>
#include <set>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <list>
#include <utility>
#include <memory>
#include <cstring>
#include <fstream>
#include <numeric>
#include <assert.h>
#include <bitset>
#include <ios> 
#include <bits/stdc++.h>
using namespace std;
int cnt[6],ok[6]; 
int n;
int ans=6;
void dfs(int x){
	if (x>=ans) return;
	for (int i=0;i<x;i++) for (int k=0;k<4;k++){
		int o=1<<k;
		cnt[x]=o*cnt[i];
		if (cnt[x]<cnt[x-1]) continue;
		if (cnt[x]>n) break;
		if (cnt[x]==n){
			ans=x;
			for (int i=1;i<=x;i++) ok[i]=cnt[i];
			return;
		}
		dfs(x+1);
	}
	for (int i=0;i<x;i++) for (int j=0;j<x;j++) for (int k=0;k<4;k++){
		int o=1<<k;
		cnt[x]=cnt[i]+cnt[j]*o;
		if (cnt[x]<cnt[x-1]) continue;
		if (cnt[x]>n) break;
		if (cnt[x]==n){
			ans=x;
			for (int i=1;i<=x;i++) ok[i]=cnt[i];
			return;
		}
		dfs(x+1);
	}
}
string dat[6]={"eax","ebx","ecx","edx","eex","edx"};
void summon_ans(int x){
	if (x>ans) return;
	cout<<"lea "<<dat[x]<<", [";
	bool t=0;
	for (int i=0;i<x && !t;i++) for (int k=0;k<4;k++){
		int o=1<<k;
		if (o*ok[i]==ok[x]){
			cout<<(char)(o+'0')<<"*"<<dat[i]<<"]";
			t=1;
			break;
		}
	}
	for (int i=0;i<x && !t;i++) for (int j=0;j<x && !t;j++) for (int k=0;k<4;k++){
		int o=1<<k;
		int q=ok[i]+ok[j]*o;
		if (q==ok[x]){
			cout<<dat[i]<<" + "<<(char)(o+'0')<<"*"<<dat[j]<<"]";
			t=1;
			break;
		}
	}
	cout<<"\n";
	summon_ans(x+1);
}
int main(){
	cin>>n; 
	cnt[0]=1;ok[0]=1;
	if (n==1){
		puts("0");return 0;
	}
	dfs(1);
	cout<<ans<<"\n";
	summon_ans(1);
}