#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#define MAXN 500010
#define INF 1000000100
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

int n,k;
string s;

char f(char x,char y){
	for(int i=0;i<3;i++)if('A'+i!=x and 'A'+i!=y)return 'A'+i;
	return 'A';
}

int main(){
	cin >> n >> k;
	cin >> s;
	if(n==1){
		cout << 0 << endl;
		cout << s;
		return 0;
	}
	if(k==2){
		int diff1=0;
		int diff2=0;
		for(int i=0;i<n;i++){
			if(s[i]!=char('A'+(i%2)))diff1++;
			else diff2++;
		}
		cout << min(diff1,diff2) << endl;
		char inizio=0;
		if(diff2<diff1)inizio++;
		for(int i=0;i<n;i++)cout << char('A'+((i+inizio)%2));
		return 0;
	}
	int res=0;
	int i=0;
	while(i<n){
		int j=i;
		while(j<n and s[j]==s[i])j++;
		char nuovo;
		if(j==n)nuovo=f(s[i],s[i]);
		else nuovo=f(s[i],s[j]);
		for(int z=i+1;z<j;z+=2){
			s[z]=nuovo;
			res++;
		}
		i=j;
	}
	cout << res << endl;
	cout << s;
}