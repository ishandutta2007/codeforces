#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 
#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
//1 .. 62 //0 //-1  -
int k; //ll //1  <<   1 ll  //6 l
long long g,n,ma,aa,bb;//log log2 log10 log_//
int main()
{
	//l l d        // d
	cin>>n>>k;//()
	ma=-1;
	for(int i=1; i<=k; ++i)
	{
		cin >> g;
		if(n/g*g>ma){
			ma=n/g*g;
			aa=i;
			bb=n/g;
		}
//		ma=max(ma,n/g*g);
	}// ll / i *i  //max //ll
	cout<<aa<<' '<<bb<<endl;
}