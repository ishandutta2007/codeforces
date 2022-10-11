#include<bits/stdc++.h>
using namespace std;
long long n,k;
int main(){
    cin>>n>>k;
    long long E=n/k;
    if(E%2==0)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
	return 0;
}