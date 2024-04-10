/******************
*  Writer: BD747  *
******************/
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

int n;
vector<int> cur;

int main(){
	cin>>n;
	if (n==1){
		cout<<1;
		return 0;
	}
	vector<int> cur;
	for (int i=1;i<=n;i++){
		cur.push_back(i);
	}
	int num=1;
	while(true){
		if(cur.size()<=3){
			if(cur.size()>2){
				cout<<num<<' ';
			}
			cout<<num<<' '<<cur[cur.size()-1];
			break;
		}
		num*=2;
		vector<int> v;
		for(int i=0;i<cur.size();i++){
			if (cur[i]%num!=0){
				cout<<num/2<<" ";
			}else{
				v.push_back(cur[i]);
			}
		}
		cur=v;
	}
	return 0;
}