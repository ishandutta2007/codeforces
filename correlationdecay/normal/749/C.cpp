#include <bits/stdc++.h>
#define maxn 200009
using namespace std;
set<int>st1,st2;
int n;
char s[maxn];
int main(){
	cin >> n;
	scanf("%s", s);
	for(int i = 0; i < n; i++){
		if(s[i] == 'D')
			st1.insert(i);
		else
			st2.insert(i);
	}
	int cur = n;
	while(!st1.empty() && !st2.empty()){
		int D = *(st1.begin());
		int R = *(st2.begin());
		st1.erase(st1.begin());
		st2.erase(st2.begin());
		if(D < R){
			st1.insert(cur);
		}
		else{
			st2.insert(cur);
		}
		cur++;
	}
	if(st1.empty()){
		puts("R");
	}
	else{
		puts("D");
	}
	//system("pause");
	return 0;
}