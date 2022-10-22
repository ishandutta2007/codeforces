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
int A,B;
string c[23]; 
bool been_same_turn_0(string s[23],string p[23],int pl){
	for (int i=0;i<pl;i++)
		for (int j=0;j<s[i].size();j++)
			if (s[i][j]!=p[i][j])
				return false;
	return true;
}
bool been_same_turn_180(string s[23],string p[23],int pl){
	for (int i=0;i<pl;i++)
		for (int j=0;j<s[i].size();j++)
			if (s[i][j]!=p[pl-i-1][s[0].size()-j-1])
				return false;
	return true;
}
bool been_same_turn_90(string s[23],string p[23],int pl){
	for (int i=0;i<pl;i++)
		for (int j=0;j<s[i].size();j++)
			if (s[i][j]!=p[j][pl-i-1])
				return false;
	return true;
}
bool been_same_turn_270(string s[23],string p[23],int pl){
	for (int i=0;i<pl;i++)
		for (int j=0;j<s[i].size();j++)
			if (p[i][j]!=s[j][pl-i-1])
				return false;
	return true; 
}
bool beensame(string s[23],string p[23],int pl){
	if (been_same_turn_0(s,p,pl)) return true;
	if (been_same_turn_180(s,p,pl)) return true;
	if (pl==s[0].size() && been_same_turn_90(s,p,pl)) return true;
	if (pl==s[0].size() && been_same_turn_270(s,p,pl)) return true;
	return false;
}
int main(){
	cin>>A>>B;
	string s[23],p[23];
	int ans1=1e4,ans2=1e4,res=0;
	for (int i=0;i<A;i++)
		cin>>c[i];
	for (int i=1;i<=A;i++)
		if (A%i==0)
			for (int j=1;j<=B;j++)
				if (B%j==0){
					bool q=1;
					for (int i1=0;i1<A && q;i1+=i)
						for (int j1=0;j1<B && q;j1+=j)
							for (int i2=0;i2<A && q;i2+=i)
								for (int j2=0;j2<B && q;j2+=j){ 
									if (i1==i2 && j1==j2) continue;
									for (int k=i1,hh=0;hh<i;k++,hh++)
										s[k-i1]=c[k].substr(j1,j); 
									for (int k=i2,hh=0;hh<i;k++,hh++)
										p[k-i2]=c[k].substr(j2,j);
									if (beensame(s,p,i)) q=0;
								}
					if (!q);
					else{
						res++;
						if (ans1*ans2>i*j || (ans1*ans2==i*j && ans1>i))
							ans1=i,ans2=j;
					} 
			}
	cout<<res<<endl<<ans1<<" "<<ans2;
	return 0;
}