#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#define rep(i,n) for(int i=1;i<=n;i++)
#define mp make_pair
#define pb push_back
using namespace std;
#define ll long long
int t[210000],l[210000];
int main()
{
	int n,L,k;
	cin>>n>>L>>k;
	rep(i,n)scanf("%d%d",&t[i],&l[i]);
	int ans=(L-t[n]-l[n])/k;
	rep(i,n)ans+=(t[i]-t[i-1]-l[i-1])/k;
	cout<<ans<<endl;
}