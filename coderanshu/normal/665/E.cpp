#include<stdio.h>
#include<unordered_map> 
#include<set>
using namespace std ;
struct node
{
	int freq;
	int L,R;
	node ():L(-1),freq(0),R(-1){}
};
const int N=1000005,NN=35;
node tr[N*NN];
int cursz=0;
inline int getnode()
{
	int v=cursz++;
	return v;
}
struct TRIE
{
	int root;
	TRIE()
	{
		root = getnode();
	}
	void insert(int n)
	{
		int temp=root;
		tr[root].freq++;
		for(int j=30;j>=0;--j)
		{
			if(n&(1<<j))
			{
				if(tr[temp].R==-1)
					tr[temp].R=getnode();
				temp=tr[temp].R;
				tr[temp].freq++;
			}
			else
			{
				if(tr[temp].L==-1)
					tr[temp].L=getnode();
				temp=tr[temp].L;
				tr[temp].freq++;
			}
		}
	}
	void erase(int n)
	{
		int temp=root;
		tr[root].freq--;
		for(int j=30;j>=0;--j)
		{
			if(n&(1<<j))
			{
				tr[tr[temp].R].freq--;
				temp=tr[temp].R;
			}
			else
			{
				 tr[tr[temp].L].freq--;
				temp=tr[temp].L;
			}
		}
	}
	int query(int Xor,int k)
	{
		int temp=root;
		int ans=0;
		for(int j=30;j>=0;--j)
		{
			if(k&(1<<j))
			{
				if(Xor&(1<<j))
				{
					if(tr[temp].L==-1)
						break;
					temp=tr[temp].L;
				}
				else
				{
					if(tr[temp].R==-1)
						break;
					temp=tr[temp].R;
				}
			}
			else
			{
				if(Xor&(1<<j))
				{
					if(tr[temp].L!=-1)
						ans+=tr[tr[temp].L].freq;
					if(tr[temp].R==-1 || tr[tr[temp].R].freq==0)
						break;
					temp=tr[temp].R;
				}
				else
				{
					if(tr[temp].R!=-1)
						ans+=tr[tr[temp].R].freq;
					if(tr[temp].L==-1 || tr[tr[temp].L].freq==0)
						break;
					temp=tr[temp].L;
				}
			}
		}
		return ans;
	}
};
TRIE trie;
int _runtimeTerror_()
{
	int n,k;
	scanf("%d %d ",&n,&k);
	int a[n],i;
	for(i=0;i<n;++i)
		scanf("%d",a+i);
	int Xor=0;
	unordered_map<int,int> m;
	for(i=0;i<n;++i)
	{
		Xor^=a[i];
		
		m[Xor]++;
		trie.insert(Xor);
	}
	Xor=0;
	long long  ans=0;
	for(i=0;i<n;++i)
	{
		ans+=m[k^Xor];
		ans+=trie.query(Xor,k);
		Xor^=a[i];
		m[Xor]--;
		trie.erase(Xor);
	}
	printf("%lld",ans);
	return 0;
}

int main()
{
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
	return 0;
}