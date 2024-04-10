#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    long long a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a,a+n);
    long long mx=a[n-1];
    long long sum=0;
    for(int i=0; i<n-1; i++){
        sum+=mx-a[i];
    }
    for(int i=0; i<=mx; i++){
        if(i*(n-1)+sum>=mx){
            cout << mx+i;
            return 0;
        }
    }
	return 0;
}