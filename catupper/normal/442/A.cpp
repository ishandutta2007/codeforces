#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#include<set>
using namespace std;
typedef pair<int, int> P;
vector<P> tcard;

int cnt(int x){
	int res = 0;
	while(x){
		res += x % 2;
		x >>= 1;
	}
	return res;
}

bool check(int x){
	vector<P> card = tcard;
	for(int i = 0;i < 10;i++){
		if((x & (1 << i)) == 0)continue; 
		for(int j = 0;j < card.size();j++){
			if(i >= 5){
				if(card[j].second == i - 5)card[j].second = -1;
			}
			else{
				if(card[j].first == i)card[j].first = -1;
			}
		}
	}
	int unknown = 0, sec = 0, fir = 0;
	set<int> firs, secs;
	for(int i = 0;i < card.size();i++){
		if(card[i].second == -1 && card[i].first == -1)continue;
		if(card[i].second != -1 && card[i].first != -1){unknown++;continue;}
		if(card[i].second != -1 && card[i].first == -1){
			fir++;
			firs.insert(tcard[i].first);
		}
		if(card[i].second == -1 && card[i].first != -1){
			sec++;
			secs.insert(tcard[i].second);
		}
	}
	if(unknown > 1)return false;
	if(sec != secs.size())return false;
	if(fir != firs.size())return false;
	return true;
}

int num[1080];
int main(){
	int n, x;
	char c;
	int res = 1 << 30;
	num['R'] = 0;
	num['G'] = 1;
	num['B'] = 2;
	num['Y'] = 3;
	num['W'] = 4;
	cin >> n;
	for(int i = 0;i < n;i++){
		scanf(" %c%d", &c, &x);
		tcard.push_back(P(num[c], x - 1));
	}
	sort(tcard.begin(), tcard.end());
	tcard.erase(unique(tcard.begin(), tcard.end()), tcard.end());
	for(int i = 0;i < (1 << 10);i++){
		if(check(i)){
			res = min(res, cnt(i));
		}
	}
	cout << res << endl;
	return 0;
}