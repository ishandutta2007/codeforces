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
typedef pair<int,int> pii;
string s;
pii a[100003];
int l=0;
bool lios(string s){
	if (s.size()<4) return false;
	if (s.substr(s.size()-4,4)=="lios") return true;
	return false; 
}
bool liala(string s){
	if (s.size()<5) return false;
	if (s.substr(s.size()-5,5)=="liala") return true;
	return false;
}
bool etr(string s){
	if (s.size()<3) return false;
	if (s.substr(s.size()-3,3)=="etr") return true;
	return false; 
}
bool etra(string s){
	if (s.size()<4) return false;
	if (s.substr(s.size()-4,4)=="etra") return true;
	return false; 
}
bool initis(string s){
	if (s.size()<6) return false;
	if (s.substr(s.size()-6,6)=="initis") return true;
	return false; 
}
bool inites(string s){
	if (s.size()<6) return false;
	if (s.substr(s.size()-6,6)=="inites") return true;
	return false; 
}
bool adj,n,v;
int main(){
	while (cin>>s){
		a[l].first=-1,a[l].second=-1;
		if (lios(s)){
			a[l++]=pii{0,0};
			continue;
		}
		if (liala(s)){
			a[l++]=pii{0,1};
			continue;
		}
		if (etr(s)){
			a[l++]=pii{1,0};
			continue;
		}
		if (etra(s)){
			a[l++]=pii{1,1};
			continue;
		}
		if (initis(s)){
			a[l++]=pii{2,0};
			continue;
		}
		if (inites(s)){
			a[l++]=pii{2,1};
			continue;
		}
		l++;
	}
	if (l==1 && a[0].first!=-1){
		cout<<"YES";
		return 0;
	}
	for (int i=0;i<l;i++){
		if (a[i].first==-1){cout<<"NO";return 0;}
		if (i==0);
		else{
			if (a[i].second!=a[i-1].second){
				cout<<"NO";
				return 0;
			}
		}
		if (a[i].first==0){
			if (n || v){cout<<"NO";return 0;}
			adj=1;
			continue;
		}
		if (a[i].first==1){
			if (n || v){cout<<"NO";return 0;}
			n=1;
			continue;
		}
		if (a[i].first==2){
			if (!n){cout<<"NO";return 0;}
			v=1;
			continue;
		}
	}
	if (!n) cout<<"NO";
	else cout<<"YES";
	return 0;
}