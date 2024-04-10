#include<bits/stdc++.h>
using namespace std;
#define ceil(x) ((long long)(x)==(x)?(x):((long long)(x)+1))
int main()
{
	long long n,k;
	cin>>n>>k;
	cout<<(long long)ceil(2.0*n/k)+(long long)ceil(5.0*n/k)+(long long)ceil(8.0*n/k);
}