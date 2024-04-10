#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
typedef long long ll;
#define lson id << 1, l, mid  
#define rson id << 1 | 1, mid, r 

//int minn[123456*8];
//int lazy[123456*8];
struct segment_tree
{
	int n;
	//	cout<<"minn.size="<<minn.size()<<endl;
//	cout<<"lazy.size="<<lazy.size()<<endl;
	vector<int>a;
	vector<int>minn;
	vector<int>lazy;
	segment_tree(const vector<int> &v):a(v)
	{
		n=a.size();
		minn.resize(n*4);
		lazy.resize(n*4);
		build(1,0,n);
	}
//	cout<<"minn.size="<<minn.size()<<endl;
//	cout<<"lazy.size="<<lazy.size()<<endl;
	void pushup(int id)
	{
		minn[id]=min(minn[id<<1],minn[id<<1|1]);
	}
	
	void build(int id,int l,int r)
	{
		lazy[id] = 0;
		if(r-l<=1)
		{
			//printf("minn[%d]=%d\n",id,minn[id]);
			minn[id]=a[l];
			return;
		}
		int mid=(l+r)>>1;
		build(lson);
		build(rson);
		minn[id]=min(minn[id<<1],minn[id<<1|1]);
		//pushup(id);
	}
	void shift(int id) 
	{
    	if (lazy[id])
		{
      		minn[id<<1]=lazy[id<<1]=minn[id<<1|1]=lazy[id<<1|1]=lazy[id];
      		lazy[id] = 0;
    	}
	}
	void update(int x, int y, int v, int id, int l, int r)
	{
    	if (x>=r || l>=y) return;
    	if (x<=l && r<=y)
		{
      		minn[id] = lazy[id] = v;
      		return;
    	}
    	shift(id);
    	int mid = (l+r)>>1;
    	update(x, y, v, lson);
    	update(x, y, v, rson);
    	minn[id] = min(minn[id<<1], minn[id<<1|1]);
	}
	int query(int x,int y,int id,int l,int r)
	{
		if(x>=r || l>=y)return 2e9;
		if(x<=l && r<=y) 
		{
			return minn[id];
		}
		shift(id);
		int mid=(l+r)>>1;
		int ans=min(query(x,y,lson),query(x,y,rson));
		return ans;
	}
};

int l[123456], r[123456];
int op[123456];
int val[123456];
//vector<int>aa;
vector<int>a;
vector<int>b;
/*
3 1
1 2 3
3
2 1 3
1 1 2 4
2 1 3

1
3
*/
int main()
{
	//freopen("in.txt","r",stdin);
	int n,k;
	cin>>n>>k;
	int limit=2e9;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		a.push_back(x);
		limit=min(limit,x);
	}
	segment_tree seg(a);
	vector<int>V;
	V.push_back(0);
	V.push_back(n*k);
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		cin>>op[i]>>l[i]>>r[i];
		l[i]--;
		if(op[i]==1)
		{
			cin>>val[i];
		}
		V.push_back(l[i]);
		V.push_back(r[i]);
	}
	sort(V.begin(),V.end());
	V.erase(unique(V.begin(),V.end()),V.end());
	
	for(int i=0;i<V.size()-1;i++)
	{
		int left = V[i];
		int right = V[i+1];
		if(right - left >= n)
		{
			b.push_back(limit);
		}
		else
		{
			right %= n;
			if(right==0)
			{
				right = n;
			}
			left %= n;
			if(left < right)
			{
				int res=seg.query(left,right,1,0,n);
				b.push_back(res);
			}
			else
			{
				int res=min(seg.query(left,n,1,0,n), seg.query(0,right,1,0,n));
				b.push_back( res );
			}
		}
	}	
	segment_tree segmt(b);
	for (int i = 0; i < q; i++)
	{
    	l[i] = lower_bound(V.begin(), V.end(), l[i]) - V.begin();
    	r[i] = lower_bound(V.begin(), V.end(), r[i]) - V.begin();
    	
    	if (op[i]==1)
    	{
			segmt.update(l[i], r[i], val[i], 1, 0, b.size());	
		} 		
    	else if(op[i]==2)
    	{
    		int ans=segmt.query(l[i], r[i], 1, 0, b.size());
    		printf("%d\n",ans);
		}
      	
  }
	return 0;
}