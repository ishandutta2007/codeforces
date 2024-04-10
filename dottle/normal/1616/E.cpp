#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

struct BIT{
    int a[N],n;
    void clr(int _n){for(int i=1;i<=n;i++)a[i]=0;n=_n;}
    void add(int k,int p){k++;while(k<=n)a[k]+=p,k+=k&-k;}
    int sum(int k){int ans=0;while(k)ans+=a[k],k-=k&-k;return ans;}
    int sum(int x,int y){x++,y++;return sum(y)-sum(x-1);}
}T;

void solve(){
	int n;string s,t;cin>>n>>s>>t;
	T.clr(n);
	set<int> S[26];
	for(int i=0;i<n;i++)
		S[s[i]-'a'].insert(i);
	int ans=1e18,sum=0;
	for(int i=0;i<n;i++){
		int mn=1e18,p=0;
		for(int j=0;j<t[i]-'a';j++){
			if(S[j].size()){
				int k=*S[j].begin();
				int dis=k+T.sum(0,k)-i;
				if(dis<mn)
					mn=dis,p=j;
			}
		}
		int k=*S[p].begin();
		ans=min(ans,sum+mn);
		if(S[t[i]-'a'].empty())break;
		k=*S[t[i]-'a'].begin();
		sum+=k+T.sum(0,k)-i;
		T.add(0,1),T.add(k,-1);
		S[t[i]-'a'].erase(k); 
	}
	if(ans<=1e15)
		cout<<ans<<endl;
	else cout<<-1<<endl;
}


main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}