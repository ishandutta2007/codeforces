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
void read(string &s){
	char ch=getchar();
	for(;ch==' '||ch=='\n';ch=getchar());
	for(;ch!=' '&&ch!='\n';s+=ch,ch=getchar());
}
int n,k;
string s;
int z[1000004];
void z_function(){
    int l=0,r=0;
    for (int i=1;i<s.size();i++){
        if (i>r){
            l=i,r=i;
            while (r<s.size() && s[r-l]==s[r]) r++;
            z[i]=r-l,r--;
        }else{
            int k=i-l;
            if (z[k]<r-i+1) z[i]=z[k];
            else{
                l=i;
                while (r<s.size() && s[r-l]==s[r]) r++;
                z[i]=r-l,r--;
        	}
        }
    }
}
int dat[1000004],num[1000004];
void ok(int x){
	for (int i=x,j=1;j<k;i+=x,j++) if (z[i]<x) return;
	dat[k*x-1]++;
	num[k*x-1+min(x,z[k*x])]++; 
}
int main(){
	cin>>n>>k;
	read(s);
	z_function();
	for (int i=0;i<=n/k;i++)
		ok(i);
	int now=0;
	for (int i=0;i<n;i++){
		now+=dat[i];
		if (now>0) putchar('1');
		else putchar('0');
		now-=num[i];
	}
}