#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

queue <int> q;

int n, m;

int f[100005];
int g[100005];
int h[100005];

int main(){
	int i, j;
	bool flag = true;
	
	cin >> n;
	
	for(i=1;i<=n;i++){
		cin >> f[i];
		if(i == f[i]){
			q.push(i);
		}
	}
	
	for(i=1;i<=n;i++){
		if(f[i] != f[f[i]]){
			flag = false;
		}
	}
	
	m = 0;
	
	while(!q.empty()){
		m++;
		h[m] = q.front();
		g[h[m]] = m;
		q.pop();
	}
	
	for(i=1;i<=n;i++){
		g[i] = g[f[i]];
	}
	
	if(!flag){
		cout << -1 << endl;
	}else{
		
		cout << m << endl;
		
		for(i=1;i<n;i++){
			cout << g[i] << " ";
		}
		cout << g[n] << endl;
		
		for(i=1;i<m;i++){
			cout << h[i] << " ";
		}
		cout << h[m] << endl;
	}
	
	return 0;
}