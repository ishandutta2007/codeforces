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
int n;
vector <int> v;
int main(){
	cin>>n;
	if (n==1){
		cout<<"1";
		return 0;
	}
	vector <int> cur;
	for (int i=1;i<=n;i++)
		cur.push_back(i);
	int num=1;
	while (1){
		if (cur.size()==2){
			cout<<num<<" "<<cur[1];
			break;
		}
		if (cur.size()==3){
			cout<<num<<" "<<num<<" "<<cur[2];
			break;
		}
		num*=2;
		vector <int> v;
		for (int i=0;i<cur.size();i++)
			if (cur[i]%num!=0) cout<<num/2<<" ";
			else v.push_back(cur[i]);
		cur=v;
	}
	return 0;
}