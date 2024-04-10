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
string s;
map <string,string> digit;
vector <vector <string> > Void;
bool okay(vector <string> a,vector <string> b){
	if (a.size()-1!=b.size()) return false;
	if (a[1]!=b[0]) return false;
	for (int i=2;i<a.size();i++){
		string nah=a[i],ww=digit[b[i-1]];
		if (nah=="T" || nah==ww) continue;
		return false;
	}
	return true;
}
int main(){
	int n,m,k;
	cin>>n;
	getline (cin,s);
	for (int i=0;i<n;i++){
		vector <string> pu;
		string x="";
		getline (cin,s);
		for (int j=0;j<s.size();j++)
			if (s[j]=='(' || s[j]==')' || s[j]==',')
				s[j]=' ';
		for (int j=0;j<s.size();j++){
			if (s[j]==' ') continue;
			else x+=s[j];
			if ((j==s.size()-1 || s[j+1]==' ') && s[j]!=' '){
				pu.push_back(x);
				x="";
			}
		}
		Void.push_back(pu);
	}
	cin>>m;
	getline (cin,s);
	for (int i=0;i<m;i++){
		getline (cin,s);
		s+=' ';
		string p[2];
		int nah=0,l=0;
		string x="";
		for (int j=0;j<s.size();j++){
			if (s[j]==' ') continue;
			else x+=s[j];
			if ((j==s.size()-1 || s[j+1]==' ') && s[j]!=' '){
				p[l++]=x;
				x="";
			}
		}
		digit[p[1]]=p[0];
	}
	cin>>k;
	getline (cin,s);
	while (k--){
		vector <string> remix;
		getline (cin,s);
		string x="";
		for (int i=0;i<s.size();i++)
			if (s[i]=='(' || s[i]==')' || s[i]==',')
				s[i]=' ';
		for (int i=0;i<s.size();i++){
			if (s[i]==' ') continue;
			else x+=s[i];
			if ((i==s.size()-1 || s[i+1]==' ') && s[i]!=' '){
				remix.push_back(x);
				x="";
			}
		}
		int ans=0;
		for (int i=0;i<n;i++)
			if (okay(Void[i],remix)) ans++;
		cout<<ans<<endl;
	}
	return 0;
}