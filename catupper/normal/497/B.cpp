#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef pair<int, int> P;

vector<int> points[3];
int next[3][108000];
int a[108000];
int last;

int check(int s){
	int win[] = {0, 0, 0};
	int p[] = {0, 0, 0};
	while(true){
		bool ok1 = true, ok2 = true;
		if(p[1] + s - 1 >= points[1].size())ok1 = false;
		if(p[2] + s - 1 >= points[2].size())ok2 = false;
		if(!ok1 && !ok2)return -1;
		if(!ok1){
			win[2]++;
			p[2] = p[2] + s;
			if(p[2] != points[2].size())continue;
			if(last == 2 && win[1] < win[2] && p[2] == points[2].size())return win[2];
			else return -1;
		}		
		if(!ok2){
			win[1]++;
			p[1] = p[1] + s;
			if(p[1] != points[1].size())continue;
			if(last == 1 && win[1] > win[2] && p[1] == points[1].size())return win[1];
			else return -1;
		}
		if(points[1][p[1] + s - 1] < points[2][p[2] + s - 1]){
			win[1]++;
			p[1] = p[1] + s;
			p[2] = next[2][points[1][p[1]-1]];
		}
		else{
			win[2]++;
			p[2] = p[2] + s;
			p[1] = next[1][points[2][p[2]-1]];
		}                       
	}
}

int main(){
	vector<P> ans;
	int n;
	cin >> n;

	for(int i = 0;i < n;i++){
		cin >> a[i];
		last = a[i];
		points[a[i]].push_back(i);
	}
	next[1][0] = next[2][0] = 0;
	for(int i = 0;i < n;i++){
		if(i){
			next[1][i] = next[1][i-1];
			next[2][i] = next[2][i-1];
		}
		next[a[i]][i]++;
	}
	
	for(int i = 1;i <= n;i++){
		int tmp = check(i);
		if(tmp != -1)ans.push_back(P(tmp, i));
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for(int i = 0;i < ans.size();i++){
		cout << ans[i].first << " " << ans[i].second << endl;
	}
	return 0;	
}