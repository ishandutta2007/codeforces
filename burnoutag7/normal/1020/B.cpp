/******************
*  Writer: Oh no  *
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
int cla[1005];
int bad[1005][1005];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>cla[i];
	}
	for(int a=1;a<=n;a++){
		int x=a;
		bad[a][x]++;
		while(bad[a][x]<2){
			x=cla[x];
			bad[a][x]++;
		}
		cout<<x<<' ';
	}
	return 0;
}