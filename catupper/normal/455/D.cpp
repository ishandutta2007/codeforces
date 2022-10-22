#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, q, lastans, num, l, r, qq, k;

vector<int> ba[400];
int cnt[400][100008];
vector<int> nums;
void creat(){
	for(int i = 0;i < 400;i++)ba[i].clear();
	for(int i = 0;i < nums.size();i++){
		cnt[i / 400][nums[i]]++;
		ba[i / 400].push_back(nums[i]);
	}
}


void shift(int l, int r){
	swap(l, r);
	int p = 0;
	while(l >= ba[p].size()){
		l -= ba[p].size();
		p++;
	}
	int move = ba[p][l];
	cnt[p][move]--;
	int pp = 0;
	r--;
	while(r >= (int)ba[pp].size()){
		r -= ba[pp].size();
		pp++;
	}
	r++;
	cnt[pp][move]++;
	ba[p].erase(ba[p].begin() + l);	
	ba[pp].insert(ba[pp].begin() + r, move);
}

int solve(int pos, int k){
	if(pos < 0)return 0;
	int p = 0, res = 0;
	while(pos >= ba[p].size()){
		pos -= ba[p].size();
		res += cnt[p++][k];
	}
	for(int i = 0;i <= pos;i++){
		if(ba[p][i] == k)res++;
	}
	return res;
}

int main(){
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> num;
		nums.push_back(num);
	}
	creat();
	cin >> q;
	for(int i = 0;i < q;i++){
		if(i % 400 == 399){
			nums.clear();
			for(int j = 0;j < 400;j++){
				for(int k = 0;k < ba[j].size();k++){
					int num = ba[j][k];
					cnt[j][num]--;
					nums.push_back(num);
				}
			}
			creat();
		}
		cin >> qq;
		if(qq == 1){
			cin >> l >> r;
			l = (l + lastans - 1) % n + 1;
			r = (r + lastans - 1) % n + 1;
			l--,r--;
			if(l > r)swap(l, r);
			shift(l, r);
		}
		if(qq == 2){
			cin >> l >> r >> k;
			l = (l + lastans - 1) % n + 1;
			r = (r + lastans - 1) % n + 1;
			k = (k + lastans - 1) % n + 1;
			l--,r--;
			if(l > r)swap(l, r);
			lastans = solve(r, k) - solve(l - 1, k);
			cout << lastans << endl;
		}
	}
	return 0;
}