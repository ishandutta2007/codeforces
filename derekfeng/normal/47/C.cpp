#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <sstream>
#include <stack>
#include <time.h>
#include <vector>
#include <complex>
#include <map>
#include <set>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <list>
#include <utility>
#include <memory>
#include <cstring>
#include <fstream>
#include <numeric>
#include <assert.h>
#include <bits/stdc++.h>
using namespace std;
string s[6];
vector <vector <string> > v;
inline char ends(string s){
	return  s[s.size()-1]; 
}
int main(){
	for (int i=0;i<6;i++)
		cin>>s[i];
	sort (s,s+6);
	do{
		if (s[0].size()+s[4].size()-1!=s[2].size()) continue;
		if (s[1].size()+s[5].size()-1!=s[3].size()) continue;
		if (s[0][0]!=s[1][0]) continue;
		if (ends(s[1])!=s[2][0]) continue;
		if (ends(s[2])!=s[5][0]) continue;
		if (ends(s[0])!=s[3][0]) continue;
		if (ends(s[3])!=s[4][0]) continue;
		if (ends(s[4])!=ends(s[5])) continue;
		if (s[2][s[0].size()-1]!=s[3][s[1].size()-1]) continue;
		vector <string> m;
		string x=s[0];
		for (int i=0;i<s[4].size()-1;i++)
			x+='.';
		m.push_back(x);
		for (int i=1;i<s[1].size()-1;i++){
			x=s[1][i];
			for (int j=0;j<s[0].size()-2;j++) x+='.';
			x+=s[3][i];
			for (int j=0;j<s[4].size()-1;j++) x+='.';
			m.push_back(x); 
		}
		m.push_back(s[2]);
		for (int i=1;i<s[5].size()-1;i++){
			x="";
			for (int j=0;j<s[0].size()-1;j++) x+='.';
			x+=s[3][s[1].size()+i-1];
			for (int j=0;j<s[4].size()-2;j++) x+='.';
			x+=s[5][i];
			m.push_back(x); 
		}
		x="";
		for (int i=0;i<s[0].size()-1;i++) x+='.';
		x+=s[4];
		m.push_back(x);
		v.push_back(m);  
	}while (next_permutation(s,s+6));
	if (v.size()==0){
		puts("Impossible");
		return 0;
	}
	sort (v.begin(),v.end());
	for (int i=0;i<v[0].size();i++)
		cout<<v[0][i]<<endl;
	return 0;
}