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
stack <int> st;
int n;
char A[100005];
string s,ans;
int main(){
	cin>>n;
	int m=0;
	while (cin>>s){
		A[m]=s[0];
		m++;
	}
	if (n==1 && m==1){
		puts("int");
		return 0;
	}
	for (int i=0;i<m;i++){
		if (A[i]=='p'){
			st.push(0);
			ans+="pair<";
		}
		else{
			if (st.empty()){
				puts("Error occurred");
				return 0;
			}
			if (st.top()==0){
				st.push(1);
				ans+="int,";
			}else{
				ans+="int>";
				st.pop();
				st.pop();
				while (!st.empty()&&st.top()!=0){
					st.pop();
					st.pop();
					ans+='>';
				}
				if (st.empty() && i!=m-1){
					puts("Error occurred");
					return 0;
				}
				if (i!=m-1){
					st.push(1);
					ans+=',';
				}
			}
		}
	}
	if (!st.empty()){
		puts("Error occurred");
		return 0;
	}
	cout<<ans;
	return 0;
}