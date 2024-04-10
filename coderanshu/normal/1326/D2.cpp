#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define sz(a) (ll)a.size()
#define F first
#define S second
#define PI 3.1415926536
#define INF 2e18
#define endl "\n"
#define llevel 20
ll power(ll b,ll e,ll m)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b%m,e/2,m)%m;
	return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b,e/2);
	return power(b*b,e/2);
}
bool palin(string &t)
{
	int n=t.length();
	for(int i=0;i<n/2;++i)
	{
		if(t[i]!=t[n-1-i])
			return false;
	}
	return true;
}
int answer(string &s)
{
	int i;
	string rev="",str=s;
    int m=s.size(),longestPalindromicPrefix=1;
    if(m==0 || m==1)    longestPalindromicPrefix=m; 
    for(int i=m-1;i>=0;i--)
        rev+=s[i];
    s+='#';
    s+=rev;
    int n=s.size(),z[n+4],l=0,r=0;
    for(int i=1;i<n;i++){
        if(i>r){
            l=r=i;
            while(r<n && s[r-l]==s[r])
                r++;
            z[i]=r-l,r--;
        }
        else{
            int k=i-l;
            if(z[k]<r-i+1)
                z[i]=z[k];
            else{
                l=i;
                while(r<n && s[r-l]==s[r])
                    r++;
                z[i]=r-l,r--;
            }
        }
    }

    for(int i=m+1;i<n;i++){
        if(2*z[i]>=2*m-i && z[i]>longestPalindromicPrefix)
            longestPalindromicPrefix=z[i];
    }
    return longestPalindromicPrefix;
}
int _runtimeTerror_()
{
	string s,anss;
	cin>>s;
	int i=0;
	int n=s.length();
	while( i<n/2 && s[i]==s[n-1-i]){anss+=s[i];++i;}
	int k=i;
	if(i==n/2)
	{
		cout<<s<<endl;return 0;
	}
	string l=s.substr(i,n-2*i);
	string m=l;
	reverse(all(l));
	int x=answer(l);
	int y=answer(m);
	if(x>y)
	{
		cout<<anss;
		for(i=0;i<x;++i)cout<<l[i];
		reverse(all(anss));
		cout<<anss<<endl;
	}
	else
	{
		cout<<anss;
		for(i=0;i<y;++i)cout<<m[i];
			reverse(all(anss));
		cout<<anss<<endl;
	}
	
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifdef runSieve
		sieve();
	#endif
	#ifdef NCR
		initialize();
	#endif
	int TESTS=1;
	cin>>TESTS;
	while(TESTS--)
		_runtimeTerror_();
	return 0;
}