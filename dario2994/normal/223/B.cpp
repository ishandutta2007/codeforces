#include <iostream>
#include <cstdlib>
#include <fstream>
#include <tr1/unordered_map>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#define MAXT 200010
#define INF 1000000100
#define rp(i,n) for(int i=0;i<n;i++)
#define rp1(i,n) for(int i=1;i<=n;i++)
using namespace std;
using namespace tr1;
typedef long long LL;
typedef unsigned long long ULL;

string s;
string t;
int dri[MAXT];
int rov[MAXT];

int main(){
	cin >> t;
	cin >> s;
	int S=s.size();
	int T=t.size();
	int pp=-1;
	int lettere[26];
	for(int i=0;i<26;i++)lettere[i]=-1;
	for(int i=0;i<T;i++){
		if(pp+1<S and t[i]==s[pp+1]){
			pp++;
			lettere[t[i]-'a']=pp;
		}
		dri[i]=lettere[t[i]-'a'];
	}
	pp=S;
	for(int i=0;i<26;i++)lettere[i]=S;
	for(int i=T-1;i>=0;i--){
		if(pp-1>=0 and t[i]==s[pp-1]){
			pp--;
			lettere[t[i]-'a']=pp;
		}
		rov[i]=lettere[t[i]-'a'];
	}
	//~ for(int i=0;i<T;i++)cout << rov[i] << " ";
	bool funge=true;
	for(int i=0;i<T;i++){
		if(dri[i]<rov[i])funge=false;
	}
	if(funge)cout << "YES";
	else cout << "NO";
}