#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
const int inf=0x3f3f3f3f;
typedef long long ll;
bool cmp(const int &x,const int &y)
{
	return x<y;
}
int a[maxn];
int n,k;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
    cin>>n>>k;
    int sum=0;
    int i,j;
    for(i=0;i<n;i++){
    	cin>>a[i];
    	sum+=a[i]/10;
    	a[i]=10-a[i]%10;
    }
    sort(a,a+n);
    for(i=0;i<n;i++)
    {
    	if(k-a[i]>=0)
    	{
    		k-=a[i];
    		sum++;
    	}
    }
    cout<<min(n*10,sum+k/10);
	return 0;
}