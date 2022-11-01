#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

int n, m, t;

string str[maxn];

char ch[] = {'a', 'e', 'i', 'o', 'u'};

pair <int, int> cnts[maxn];

int d[maxn];

vector <pair <int, int> > veca;
vector <pair <int, int> > vecb;
vector <int> vec;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

bool cmp(int x, int y){
	return cnts[x] > cnts[y];
}

int main(){
	ios::sync_with_stdio(false);
	int i, j, k;
	
	cin >> n;
	
	for(i=1;i<=n;i++){
		cin >> str[i];
		d[i] = i;
		int cnt = 0;
		int c = 5;
		for(j=0;j<str[i].length();j++){
			for(k=0;k<5;k++){
				if(str[i][j] == ch[k]){
					cnt++;
					c = k;
					break;
				}
			}
		}
		
		cnts[i] = make_pair(cnt, c);
	}
	
	sort(d + 1, d + n + 1, cmp);
	
	for(i=1;i<=n;i++){
		if(i == n){
			vec.push_back(d[i]);
			break;
		}
		if(cnts[d[i]].first == cnts[d[i + 1]].first and cnts[d[i]].second == cnts[d[i + 1]].second){
			veca.push_back(make_pair(d[i], d[i + 1]));
			i++;
		}else{
			vec.push_back(d[i]);
		}
	}
	
	for(i=0;i<vec.size();i++){
		if(i + 1 == (int)vec.size()){
			break;
		}
		if(cnts[vec[i]].first == cnts[vec[i + 1]].first){
			vecb.push_back(make_pair(vec[i], vec[i + 1]));
			i++;
		}
	}
	
	while(vecb.size() < veca.size()){
		vecb.push_back(veca.back());
		veca.pop_back();
	}
	
	cout << veca.size() << endl;
	
	for(i=0;i<veca.size();i++){
		cout << str[vecb[i].first] << " " << str[veca[i].first] << endl;
		cout << str[vecb[i].second] << " " << str[veca[i].second] << endl;
	}
	
	return 0;
}