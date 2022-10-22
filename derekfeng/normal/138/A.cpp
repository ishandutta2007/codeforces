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
int N,K;
bool aabb[2504],abab[2504],aaaa[2504],abba[2504];
string to_k(string s){
	int i,pl=K;
	for (i=s.size()-1;pl>0 && i>=0;i--){
		if (s[i]=='a') pl--;
		if (s[i]=='e') pl--;
		if (s[i]=='i') pl--;
		if (s[i]=='o') pl--;
		if (s[i]=='u') pl--;
	}
	if (pl>0) return "****"; 
	else return s.substr(i+1);
}
int main(){
	cin>>N>>K;
	string s1,s2,s3,s4;
	for (int i=0;i<N;i++){
		cin>>s1>>s2>>s3>>s4;
		string s11=to_k(s1),s22=to_k(s2),s33=to_k(s3),s44=to_k(s4);
		if (s11=="****" || s22=="****" || s33=="****" || s44=="****") continue;
		if (s11==s22 && s22==s33 && s33==s44) aaaa[i]=1;
		if (s11==s44 && s22==s33) abba[i]=1;
		if (s11==s33 && s22==s44) abab[i]=1;
		if (s11==s22 && s33==s44) aabb[i]=1;
	}
	for (int i=0;i<N;i++){
		if (!aaaa[i]) break;
		if (i==N-1){
			cout<<"aaaa";
			return 0;
		}
	}
	for (int i=0;i<N;i++){
		if (!aabb[i]) break;
		if (i==N-1){
			cout<<"aabb";
			return 0;
		}
	}
	for (int i=0;i<N;i++){
		if (!abba[i]) break;
		if (i==N-1){
			cout<<"abba";
			return 0;
		}
	}
	for (int i=0;i<N;i++){
		if (!abab[i]) break;
		if (i==N-1){
			cout<<"abab";
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}