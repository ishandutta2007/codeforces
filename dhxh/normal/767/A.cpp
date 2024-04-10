#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int n;

int tree[100005];
int c = 0;

int a[100005];
int b[100005];

priority_queue <int> q;
int p = 1;

bool cmp(int x, int y){
	return x > y;
}

int main(){
	int i, j;
	int x;
	
	cin >> n;
	
	for(i=1;i<=n;i++){
		cin >> a[i];
		b[i] = a[i];
	}
	
	sort(a + 1, a + n + 1, cmp);
	
	for(i=1;i<=n;i++){
		q.push(b[i]);
		while(!q.empty()){
			x = q.top();
			if(x == a[p]){
				p++;
				q.pop();
				cout << x << " ";
			}else{
				break;
			}
		}
		cout << endl;
	}
	
	return 0;
}