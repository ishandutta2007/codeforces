#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
set<int>se; 
int main()  
{  
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
    	int a;
		cin>>a;
		se.insert(a); 
	}
	if(se.size()==1){
		cout<<"NO"<<endl;
		exit(0); 
	}
	int i = 1;
	for(auto x : se)
	{
		if(i==2) cout<<x<<endl;
		i++;
	}
    return 0;  
}