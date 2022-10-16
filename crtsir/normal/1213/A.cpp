#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a,cnt1=0,cnt2=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		if(a%2)cnt1++;else cnt2++;
	}
	cout<<min(cnt1,cnt2);
}