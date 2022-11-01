#include<bits/stdc++.h>
using namespace std;
int a[100010];

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		//s.insert(a);
	}
	int ans=0;
	if(n<=2)return 0*printf("%d",0);
	sort(a,a+n);
	for(int i=1;i<n-1;i++){
		if(a[i]>a[0]&&a[i]<a[n-1]){
		 ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}