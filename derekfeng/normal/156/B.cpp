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
#include <bits/stdc++.h>
#include <windows.h> 
using namespace std;
int n,m,cil=0,cnt=0,whom[100004],pri[100004],unpri[100004];
string s;
bool vis[100004];
bool bad_man[100004];
string ans[3]={"Lie","Truth","Not defined"};
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>s;
		if (s[0]=='+') vis[i]=1;
		else{
			vis[i]=0;
			cil++;
		}
		int num=0;
		for (int j=1;j<s.size();j++) num=num*10+s[j]-'0';
		whom[i]=num;
		if (s[0]=='+') pri[num]++;
		else unpri[num]++;
	}
	for (int i=1;i<=n;i++){
		int pp=pri[i]+cil-unpri[i];
		if (pp==m){
			cnt++;
			bad_man[i]=1;
		}
	}
	for (int i=1;i<=n;i++){
		if (i!=1) cout<<endl; 
		if (vis[i]==1){ 
			if (!bad_man[whom[i]]){
				cout<<ans[0];
				continue;
			}
			if (cnt>1){
				cout<<ans[2];
				continue;
			}
			cout<<ans[1];
		}
		else{
			if (bad_man[whom[i]] && 1==cnt){
				cout<<ans[0];
				continue;
			}
			if (bad_man[whom[i]]){
				cout<<ans[2];
				continue;
			}
			cout<<ans[1];
		}
	}
	return 0;
}