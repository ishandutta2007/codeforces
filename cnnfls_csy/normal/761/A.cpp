#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
using namespace std;
int n,m;
int main()
{
	 cin>>n>>m;
	 if (n==m&&n==0) cout<<"NO";
	 else if (abs(n-m)>1) cout<<"NO";
	 else cout<<"YES";
	 return 0;
}