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
int l,num=1e9;string s,ans;
string t(string a,string b){
	if (a.size()<b.size()) swap(a,b);
	string res;
	int qq=0;
	for (int i=b.size()-1,j=a.size()-1;i>=0;i--,j--){
		a[j]-='0';b[i]-='0';
		res+=char((a[j]+b[i]+qq)%10+'0');
		qq=(a[j]+b[i]+qq>=10?1:0);
	}
	for (int i=a.size()-b.size()-1;i>=0;i--){
		a[i]-='0';
		res+=char((a[i]+qq)%10+'0');
		qq=(a[i]+qq==10?1:0);
	}
	if (qq==1) res+="1";
	reverse (res.begin(),res.end());
	return res;
}
int main(){
	cin>>l>>s;
	for (int i=(l-1)/2,j=l/2;j<l;i--,j++){
		if (s[j]=='0');else{
			if (num>=max(l-j,j)){
				string tat=t(s.substr(0,j),s.substr(j));
				if (num>tat.size() || (num==tat.size()&&ans>tat)){
					ans=tat;
					num=tat.size(); 
				}
			}
		}
		if (s[i]=='0');else{
			if (num>=max(l-i,i)){
				string tat=t(s.substr(0,i),s.substr(i));
				if (num>tat.size() || (num==tat.size()&&ans>tat)){
					ans=tat;
					num=tat.size(); 
				}
			}
		}
	}
	cout<<ans;
}