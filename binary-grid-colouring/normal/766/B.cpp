#include<bits/stdc++.h>
using namespace std;
int a[100007];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(i+1<n &&i+2<n){
			if(a[i]+a[i+1]>a[i+2]){
				return 0*puts("YES");
			} 
		}
	}
	puts("NO");
	return 0;
}