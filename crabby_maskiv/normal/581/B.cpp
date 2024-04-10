#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
const int inf=0x3f3f3f3f;
typedef long long ll;
int suf[maxn];
int n;
int a[maxn];
int ans[maxn];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
    cin>>n;
    int i,j;
    for(i=0;i<n;i++) cin>>a[i];
    for(i=n-1;i>=0;i--)
    {
    	if(a[i]>suf[i+1])
    	{
    		suf[i]=a[i];
    		ans[i]=0;
    	}
    	else
    	{
    		suf[i]=suf[i+1];
    		ans[i]=suf[i]-a[i]+1;
    	}
    }
    for(i=0;i<n;i++) cout<<ans[i]<<" ";
	return 0;
}