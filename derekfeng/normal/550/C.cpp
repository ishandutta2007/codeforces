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
bool div8[1000];
int a[1000];
void print(int x){
	cout<<"Yes"<<endl<<x;
	exit(0);
}
int main(){
	string s;
	cin>>s;
	for (int i=0;i<1000;i+=8)
		div8[i]=1;
	for (int i=0;i<s.size();i++)
		a[i]=s[i]-'0';
	for (int i=0;i<s.size();i++)
		if (div8[a[i]])
			print(a[i]);
	for (int i=0;i<s.size();i++)
		for (int j=i+1;j<s.size();j++){
			int x=a[i]*10+a[j];
			if (div8[x])
				print(x);
		}
	for (int i=0;i<s.size();i++)
		for (int j=i+1;j<s.size();j++)
			for (int k=j+1;k<s.size();k++){
				int x=a[i]*100+a[j]*10+a[k];
				if (div8[x])
					print(x);
			}
	cout<<"No";
	return 0;
}