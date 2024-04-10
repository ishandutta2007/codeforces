#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

int u[105];
vector<int> lang[105];
set<int> nums;
int n, m, k, tmp, numbers;
int root(int x){
    if(u[x] == x)return x;
    else return u[x] = root(u[x]);
}

void unite(int x, int y){
    x = root(x);
    y = root(y);
    u[x] = y;
}

void init_union(){
    for(int i = 0;i < 105;i++)
	u[i] = i;
}
int main(){
    cin >> n >> m;
    for(int i = 0;i < n;i++){
	cin >> k;
	for(int j = 0;j < k;j++){
	    cin >> tmp;
	    lang[tmp].push_back(i);
	    numbers++;
	}
    }
    if(numbers == 0){
	cout << n << endl;
	return 0;
    }
    init_union();
    for(int i = 1;i <= 100;i++){
	for(int j = 0;j + 1 < lang[i].size();j++){
	    unite(lang[i][j], lang[i][j + 1]);
	}
    }
    for(int i = 0;i < n;i++){
	nums.insert(root(i));
    }
    cout << nums.size() - 1 << endl;
    return 0;
}