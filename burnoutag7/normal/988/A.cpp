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
int n,k,a[110],cnt;
set<int> t;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(t.count(a[i])){
			a[i]=0;
		}else{
			t.insert(a[i]);
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]>0){
			cnt++;
		}
	}
	if(cnt<k){
		cout<<"NO";
	}else{
		cout<<"YES"<<endl;
		int i=1;
		while(k){
			if(a[i]){
				cout<<i<<' ';
				k--;
			}
			i++;
		}
	}
	return 0;
}