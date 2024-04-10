#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int arr[100001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,n1,n2;
    cin>>n>>n1>>n2;
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }
    sort(arr,arr+n);
    double fin=0;
    double fin2=0;
    for(int i=0;i<n1;i++){
    	fin+=(double)arr[n-i-1];
    }
    fin/=n1;
	for(int i=0;i<n2;i++){
		fin2+=(double)arr[n-i-n1-1];
	}
	fin2/=n2;
	double fin3=0;
	double fin4=0;
	for(int i=0;i<n2;i++){
		fin3+=(double)arr[n-i-1];
	}
	fin3/=n2;
	for(int i=0;i<n1;i++){
		fin4+=(double)arr[n-i-n2-1];
	}
	fin4/=n1;
	printf("%f",max(fin3+fin4,fin+fin2));
    return 0;
}