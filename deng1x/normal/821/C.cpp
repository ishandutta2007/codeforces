#include <bits/stdc++.h>

#define MAXN (300010)

int n;
std::set<int> set;
std::stack<int> stack;

int main(){
	scanf("%d", &n);
	int ans = 0, now = 1;
	for(int i = 1; i <= n + n; ++ i){
		char opt[10];
		int x;
		scanf("%s", opt);
		if(opt[0] == 'a'){
			scanf("%d", &x);
			stack.push(x);
		}
		else{
			if(!stack.empty() && stack.top() == now){
				stack.pop();
				++ now;
				continue;
			}
			if(!stack.empty()){
			    ++ ans;
			    while(!stack.empty()){
			 	    set.insert(stack.top());
			    	stack.pop();
			    }
			}
			set.erase(set.begin());
			++ now;
				
		}
	}
	printf("%d\n", ans);
	return 0;
}