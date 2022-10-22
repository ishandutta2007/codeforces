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
#include <bitset>
#include <ios> 
#include <bits/stdc++.h>
using namespace std;
int c[26];
int main(){
	int n;cin>>n;
	while (n--){
		string s,t,p;
		cin>>s>>t>>p;
		for (int i=0;i<26;i++) c[i]=0;
		for (int i=0;i<p.size();i++) c[p[i]-'a']++;
		if (s.size()>t.size()){
			cout<<"NO\n";continue;
		}
		int i,j;
		for (i=0,j=0;j<t.size();){
			if (i<s.size() && s[i]==t[j]){
				i++,j++;
			}
			else{
				if (c[t[j]-'a']==0){
					break;
				}
				c[t[j]-'a']--;
				j++;
			}
		}
		if (j==t.size() && i==s.size())cout<<"YES\n";
		else cout<<"NO\n";
	}
}