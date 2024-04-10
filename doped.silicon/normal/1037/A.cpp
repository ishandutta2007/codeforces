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
    lli k=1,p=1;
    while(n>k)
    {
    	p++;
    	k=pow(2,p)-1;
    	//cout<<k<<"d"<<endl;
    }
    cout<<p;
	return 0;
}