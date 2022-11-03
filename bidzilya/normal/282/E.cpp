#include <iostream>
#include <queue>
#include <string>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <iomanip>
#include <stack>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const double eps = 1e-8;
const double PI = acos(-1.0);

struct Node
{
	Node* s[2];
};

inline bool bit(int i,ll x)
{
	return ((x >> i)&1);
}

Node* root;

void build()
{
	root = new Node();
	Node* tmp=root;
	for (int itr=0; itr<50; itr++)
	{
		tmp->s[0]=new Node();
		tmp=tmp->s[0];
	}
}

ll find(ll x)
{
	ll res=0;
	Node *tmp=root;
	for (int itr=49; itr>=0; itr--)
		if (bit(itr,x))
		{
			if (tmp->s[0]!=NULL)
				tmp=tmp->s[0];
			else
			{
				tmp=tmp->s[1];
				res += (1LL << itr);
			}
		}else
		{
			if (tmp->s[1]!=NULL)
			{
				tmp=tmp->s[1];
				res += (1LL << itr);
			}
			else
				tmp=tmp->s[0];
		}
	return res;
}

void add(ll x)
{
	Node* tmp=root;
	for (int itr=49; itr>=0; itr--)
		if (bit(itr,x))
		{
			if (tmp->s[1]==NULL)
				tmp->s[1]=new Node();
			tmp=tmp->s[1];
		}else
		{
			if (tmp->s[0]==NULL)
				tmp->s[0]=new Node();
			tmp=tmp->s[0];
		}
}

const int N = 111111;
ll lft[N],rght[N],a[N];
int n;

int main()
{
	#ifndef ONLINE_JUDGE 
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	cin >> n;
	for (int i=1; i<=n; i++)cin >> a[i];
	for (int i=1; i<=n; i++)
		lft[i]=lft[i-1]^a[i];
	for (int i=n; i>=0; i--)
		rght[i]=rght[i+1]^a[i];
	build();
	ll ans=0;
	for (int i=n; i>=0; i--)
	{
		ll x=find(lft[i]);
		ans=max(ans,x^lft[i]);
		add(rght[i]);
	}
	cout << ans << endl;
	return 0;
}