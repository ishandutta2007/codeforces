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
int n,now;
int p[11],ans[15];
vector <int> res1,res2,res3,res4;
void go(int m){
	for (int i=1;i<=3 && i<=m;i++)
		for (int j=1;j<=3 && i+j<=m;j++)
			for (int k=1;k<=3 && i+j+k<=m;k++){
				int l=m-i-j-k;
				if (l<1 || l>3) continue;
				int a1=0,a2=0,a3=0,a4=0;
				string s1,s2,s3,s4;
				for (int q=1;q<=i;q++){
					a1=a1*10+ans[q];
					s1+=char(ans[q]+'0');
				}
				for (int q=i+1;q<=i+j;q++){
					a2=a2*10+ans[q];
					s2+=char(ans[q]+'0');
				}
				for (int q=i+j+1;q<=i+j+k;q++){
					a3=a3*10+ans[q];
					s3+=char(ans[q]+'0');
				}
				for (int q=i+j+k+1;q<=m;q++){
					a4=a4*10+ans[q];
					s4+=char(ans[q]+'0'); 
				}
				if (s1[0]=='0' && i!=1) continue;
				if (s2[0]=='0' && j!=1) continue;
				if (s3[0]=='0' && k!=1) continue;
				if (s4[0]=='0' && l!=1) continue;
				if (a1>255 || a2>255 || a3>255 || a4>255) continue;
				res1.push_back(a1),res2.push_back(a2),res3.push_back(a3),res4.push_back(a4);    
			}
}
void dfs(int x,int joi){
	if (x>7) return;
	x--;
	if (joi==now){
		for (int i=0;i<x;i++)
			ans[2*x-i]=ans[i+1];
		go(x*2);
		for (int i=1;i<x;i++)
			ans[2*x-i]=ans[i];
		go(x*2-1);
	}
	x++;
	for (int i=1;i<=n;i++){
		ans[x]=p[i];
		dfs (x+1,joi|(1<<p[i]));
	}
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>p[i];
		now|=(1<<p[i]);
	}
	if (n>6){
		puts("0");
		return 0;
	}
	dfs (1,0);
	cout<<res1.size()<<endl;
	for (int i=0;i<res1.size();i++)
		cout<<res1[i]<<"."<<res2[i]<<"."<<res3[i]<<"."<<res4[i]<<endl; 
	return 0;
}