#include<bits/stdc++.h>
using namespace std;
int s[500003];
int n,k;
char str;
void chuli(){
    cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			cin>>str;
            s[i]=str-'a';
		}
		sort(s+1,s+1+n);
}
void solve(){
    cout<<(char)(s[1]+'a');
		int temp=n-k;
        int tt=temp/k;
		for(int i=1;i<=tt;i++)
		cout<<(char)(s[k+1]+'a');
		if(tt*k<temp) cout<<(char)(s[k+1]+'a');
		cout<<endl;
}
int main()
{
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--)
	{
        chuli();
		if(s[1]!=s[k])
		{
			cout<<(char)(s[k]+'a')<<endl;
			continue;
		}
		if(s[n]!=s[k+1]) {
			for(int i=k;i<=n;i++)
			cout<<(char)(s[i]+'a');
			cout<<endl;
			continue;
		}
        solve();
	}
}