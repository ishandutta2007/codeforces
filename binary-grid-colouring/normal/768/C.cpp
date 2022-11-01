#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int a[maxn];
int L[maxn],S[maxn];
int main()
{
	int n,k,x;
	cin>>n>>k>>x;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++){
			if(j%2==0)
			a[j]=a[j]^x;
		}
		sort(a,a+n);
		S[i]=a[0];
		L[i]=a[n-1];
		// 
		if(i>=2)
		if(S[i]==S[i-1]&&S[i]==S[i-2]&&L[i]==L[i-1]&&L[i]==L[i-2])
		break;
		
	}
	cout<<a[n-1]<<" "<<a[0]<<endl;
	return 0;
}
/*
5 1 2
9 7 11 15 5

13 7
*/