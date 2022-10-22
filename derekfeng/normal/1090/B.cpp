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
string orders[105];
string t[100005];
map <string,string> ans;
int do_it(string s){
	int ld=0;
	for (int i=0;i<s.size();i++)
		if (s[i]=='{'){
		    int j;
			for (j=i+1;s[j]!='}';j++);
			j--;
			orders[ld++]=s.substr(i+1,j-1-i);
			i=j+1;
		}
	return ld;
}
void made_in(string o){
	for (int i=0;i<o.size();i++)
		if (o[i]=='{'){
			int j;
			for (j=i+1;o[j]!='}';j++);
			j--;
			ans[o.substr(i+1,j-1-i)]=o;
			break;
		}
}
bool right_p(int x,string p){
	for (int i=0;i<p.size();i++)
		if (p[i]=='{'){
			int j;
			for (j=i+1;p[j]!='}';j++);
			j--;
			if (p.substr(i+1,j-1-i)==orders[x]) return true;
			else return false;
		}
}
string s;
int main(){
	bool okay=1;
	string kil;
	while(getline (cin,kil)){
		if (kil!="\\begin{thebibliography}{99}")
			s+=kil;
		else break;
	}
	int x=do_it(s); 
	for (int i=0;i<x;i++){
		getline(cin,t[i]);
		made_in(t[i]);
		if (!right_p(i,t[i]))  okay=0;
	}
	getline (cin,s);
	if (okay) puts("Correct");
	else{
		puts("Incorrect");
		puts("\\begin{thebibliography}{99}");
		for (int i=0;i<x;i++)
			cout<<ans[orders[i]]<<endl;
		puts("\\end{thebibliography}");
	}
	return 0;
}