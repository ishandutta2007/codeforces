#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb() push_back()
#define pp() pop_back()
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n,s,ans=0;
    cin>>n>>s;
    lli a[n];
    for(lli i=0;i<n;i++)
    cin>>a[i];
    lli k=-1;
    sort(a,a+n);
    //cout<<n;
    for(int i=0;i<n-1;i++)
    {
    	if(s==a[i]||s>=a[i]&&s<=a[i+1])
    	{
    		k=i;
    		break;
    	}
    }
    //cout<<k<<endl;
    if(k==-1)
    {
    	k=n-1;
    	//cout<<k;
    }
    if(a[0]>s)
    k=-1;
    if(k<(n-1)/2){
    k++;
    for(int i=k;i<=(n-1)/2;i++){
    	ans+=abs(a[i]-s);
    }
    
    }
    else{
    //	cout<<"hi";
    for(int i=(n-1)/2;i<=k;i++)
    {
    //	cout<<a[i]<<endl;
    	ans+=abs(s-a[i]);
    }
    }
    cout<<ans;
	return 0;
}