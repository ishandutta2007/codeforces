#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#define INF 1000000100
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

int k;
int nn[26];

int main(){
	cin >> k;
	string s;
	cin >> s;
	int l=s.size();
	for(int i=0;i<l;i++)nn[s[i]-'a']++;
	bool funge=true;
	for(int i=0;i<26;i++)if(nn[i]%k)funge=false;
	if(!funge){
		cout << -1;
		return 0;
	}
	for(int i=0;i<26;i++)nn[i]/=k;
	for(int i=0;i<k;i++){
		for(int j=0;j<26;j++){
			for(int w=0;w<nn[j];w++)cout << char('a'+j);
		}
	}
}