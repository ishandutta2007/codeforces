#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define pp() pop_back()
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	lli n;
	cin>>n;
	vector<lli>v;
	lli x[n];
	
//	cout<<v.size();
            for(int i=0;i<n;i++)
            {
	    cin>>x[i];	
            }
            sort(x,x+n);
	for(int i=0;i<n;i++)
	{
	    
	    int flag=0;
	    for(int j=0;j<v.size();j++)
	    {
	    	if(v[j]<=x[i])
	    	{
	    		flag=1;
	    		v[j]++;
	    		break;
	    	}
	    }
	    if(!flag){
	    v.push_back(1);
	    	
	    }
	    
	   // cout<<v.size();
	}cout<<v.size();
	return 0;
}