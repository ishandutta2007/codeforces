#include<bits/stdc++.h>
using namespace std;
long long a[200003],n,x,lastp=1,cnt,lastn;
int main(){
	cin>>n;
	for(int i=0;i<n;i++)scanf("%lld",&x),a[i]=((x>0)?1:-1)*(i?a[i-1]:1);
	for(int i=0;i<n;i++)
	{
		if(a[i]>0)
			cnt+=lastp,
			lastp++;
		else
			cnt+=lastn,
			lastn++;
	}
	cout<<n*(n+1)/2-cnt<<' '<<cnt;
}