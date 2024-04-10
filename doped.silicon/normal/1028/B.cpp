#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb() push_back()
#define pp() pop_back()
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n,m;
    cin>>n>>m;
    lli x=2*n/9+5;
    
    for(int i=0;i<x;i++)
    {
    	if(i%2==0)
    	cout<<"4";
    	else
    	cout<<"5";
    }cout<<"5";
    cout<<'\n';
    
    for(int i=0;i<x;i++)
    {
    	if(i%2==0)
    	cout<<"5";
    	else
    	cout<<"4";
    }cout<<"5";
	return 0;
}