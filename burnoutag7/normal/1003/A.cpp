#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
using namespace std;
set<int> a[105];
int cnt;
int n;
int coin[105];
int main(){
	cin>>n;
	cnt=1;
	for(int i=1;i<=n;i++){
		cin>>coin[i];
		bool flag=0;
		for(int j=1;j<=cnt;j++){
			if(!a[j].count(coin[i])){
				a[j].insert(coin[i]);
				flag=1;
				break;
			}
		}
		if(!flag){
			cnt++;
			a[cnt].insert(coin[i]);
		}
	}
	cout<<cnt<<endl;
	return 0;
}