#include<iostream>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
typedef long long Int;
typedef pair<Int, Int> P;
typedef pair<Int, P> T;

Int l[8][3];
Int ans[10];
Int dist(Int a, Int b){
	Int x = l[a][0] - l[b][0];
	Int y = l[a][1] - l[b][1];
	Int z = l[a][2] - l[b][2];
	return x * x + y * y + z * z;
}

void check(){
	Int tmp = 1LL << 60, lng = 0;
	Int cnt = 0;
	for(Int i = 1;i < 8;i++){
		tmp = min(tmp, dist(i, 0));
		lng = max(lng, dist(i, 0));
	}
	if(lng != tmp * 3)return;
	for(Int i = 1;i < 8;i++){
		if(tmp == dist(i, 0))ans[cnt++] = i;
		
	}
	if(cnt != 3)return;
	set<T> node;
	for(Int i = 0;i < 2;i++)
		for(Int j = 0;j < 2;j++)
			for(Int k = 0;k < 2;k++) 
				node.insert(T(l[0][0] * (1 - i - j - k) + l[ans[0]][0] * i + l[ans[1]][0] * j + l[ans[2]][0] * k,
							  P(l[0][1] * (1 - i - j - k) + l[ans[0]][1] * i + l[ans[1]][1] * j + l[ans[2]][1] * k,
							  l[0][2] * (1 - i - j - k) + l[ans[0]][2] * i + l[ans[1]][2] * j + l[ans[2]][2] * k)));
	for(Int i = 0;i < 8;i++){
		set<T>::iterator it = node.find(T(l[i][0], P(l[i][1], l[i][2])));
		if(it == node.end())return;
		node.erase(it);
	}
	cout << "YES" << endl;
	for(Int i = 0;i < 8;i++){
		cout << l[i][0] << " " << l[i][1] << " " << l[i][2] << endl;
	}
	exit(0);
}

void dfs(Int x){
	if(x == 8){
		check();
		return;
	}
	do{
		dfs(x+1);
	}while(next_permutation(l[x], l[x] + 3));
	sort(l[x], l[x] + 3);
}

int main(){
	for(Int i = 0;i < 8;i++)
		for(Int j = 0;j < 3;j++)
			cin >> l[i][j];
	
	for(Int i = 0;i < 8;i++)
		sort(l[i], l[i] + 3);
	
	dfs(0);
	cout << "NO" << endl;
	return 0;	
}