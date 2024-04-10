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
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
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
struct node
{
	ll freq;
	node* child[2]={NULL,NULL};
};
node* getnode()
{
	node* ret=new node();
	ret->child[0]=NULL;
	ret->child[1]=NULL;
	ret->freq=0;
	return ret;
}
struct TRIE
{
	node *root;
	TRIE()
	{
		root = getnode();
	}
	void insert(ll n)
	{
		node *temp=root;
		root->freq++;
		for(ll j=30;j>=0;--j)
		{
			if(n&(1<<j))
			{
				if(temp->child[1]==NULL)
					temp->child[1]=getnode();
				temp->child[1]->freq++;
				temp=temp->child[1];
			}
			else
			{
				if(temp->child[0]==NULL)
					temp->child[0]=getnode();
				temp->child[0]->freq++;
				temp=temp->child[0];
			}
		}
	}
	void erase(ll n)
	{
		node *temp=root;
		root->freq--;
		for(ll j=30;j>=0;--j)
		{
			if(n&(1<<j))
			{
				temp->child[1]->freq--;
				temp=temp->child[1];
			}
			else
			{
				 temp->child[0]->freq--;
				 temp=temp->child[0];
			}
		}
	}
	ll query(ll n)
	{
		node *temp=root;
		ll ans=0;
		for(ll j=30;j>=0;--j)
		{
			if(n&(1<<j))
			{
				if(temp->child[0]!=NULL && temp->child[0]->freq)
				{
					ans+=1<<j;temp=temp->child[0];
				}
				else
					temp=temp->child[1];
			}
			else
			{
				if(temp->child[1]!=NULL && temp->child[1]->freq)
					ans+=1<<j,temp=temp->child[1];
				else
					temp=temp->child[0];
			}
		}
		return ans;
	}
};
int _runtimeTerror_()
{
	TRIE trie;
	ll q;
	cin>>q;
	trie.insert(0);
	while(q--)
	{
		ll val;char c;
		cin>>c>>val;
		if(c=='?')
			cout<<trie.query(val)<<endl;
		else if(c=='+')
			trie.insert(val);
		else trie.erase(val);
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
	//cin>>TESTS;
	while(TESTS--)
		_runtimeTerror_();
	cerr<<_time_;
	return 0;
}