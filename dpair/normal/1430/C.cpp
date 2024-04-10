#include <bits/stdc++.h>
using namespace std;
int n;

priority_queue <int> q;

int main(){
	int t;
	scanf("%d", &t);
	while(t --){
		scanf("%d", &n);
		while(!q.empty()) q.pop();
		for (register int i = 1;i <= n;i ++){
			q.push(i);
		}
		while(q.size() > 1){
			int x = q.top();q.pop();
			int y = q.top();q.pop();
			int num = ((x + y) >> 1) + ((x + y) & 1);
			q.push(num);
		}
		printf("%d\n", q.top());
		while(!q.empty()) q.pop();
		for (register int i = 1;i <= n;i ++){
			q.push(i);
		}
		while(q.size() > 1){
			int x = q.top();q.pop();
			int y = q.top();q.pop();
			int num = ((x + y) >> 1) + ((x + y) & 1);
			q.push(num);
			printf("%d %d\n", x, y);
		}
	}
}