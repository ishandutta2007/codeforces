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
    lli ar[m][26];
    for(int i=0;i<m;i++)
    {
    	for(int j=0;j<26;j++)
    	{
    	       ar[i][j]=0;	
    	}
    }
    char c;
    for(int i=0;i<n*m;i++)
    {
    	cin>>c;
    //	cout<<i%n<<" "<<c-65<<endl;
    	ar[i%m][c-65]++;
    }
    lli s[m];
    for(int i=0;i<m;i++)
    s[i]=0;
    for(int i=0;i<m;i++)
    {
    	for(int j=0;j<26;j++)
    	{
    	       if (ar[i][j]>0)
    	       s[i]++;
    	      // cout<<i<<"  "<<s[i]<<endl;
    	}
    }
    lli mod=1000000007,ans=1;
    for(int i=0;i<m;i++)
    {
    	ans=(ans*s[i])%mod;
    //	cout<<s[i]<<endl;
    }
    cout<<ans;
	return 0;
}