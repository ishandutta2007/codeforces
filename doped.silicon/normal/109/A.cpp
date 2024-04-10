#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb() push_back()
#define pp() pop_back()
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n;
    cin>>n;
    lli k=n%7,d=n/7;;
    while(k%4!=0&&d>=0)
    {
    	k+=7;
    	d--;
    }
    if(d>=0)
    {
    	for(int i=0;i<k/4;i++)
    	cout<<"4";
    	for(int i=0;i<d;i++)
    	cout<<"7";
    }
    else{
    	cout<<"-1";
    }
    
	return 0;
}