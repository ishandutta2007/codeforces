#include<bits/stdc++.h>
using namespace std;
int ans[16]={1,0,0,1,0,1,0,1,1,1,0,0,1,0,1,0},k;
int main(){
	cin>>k;
	cout<<ans[k-1];
}