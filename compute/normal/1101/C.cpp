#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
struct node
{
    int l=0,r=0,index,ans;
	bool operator<(const node &a)const
	{
		if(l==a.l) return r<a.r;
		return l<a.l;
	}
}a[maxn];

bool cmp2(const node& x,const node& y)
{
    return x.index<y.index;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
    int T; 
	cin>>T;
    while(T--)
    {
        int n;
		cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i].l>>a[i].r;
            a[i].index=i;
			a[i].ans=0;
        }
        sort(a,a+n);
        bool fnd=false;
        int mx=-1;
        for(int i=0;i<n-1;i++)
        {
            if(!fnd)
            {
                mx=max(mx,a[i].r);
                if(mx<a[i+1].l)
                {
                    fnd=true;
                }
                a[i].ans=1;
            }
            else
            {
                a[i].ans=2;
            }
        }
        if(fnd)
            a[n-1].ans=2;
        if(fnd==false)
        {
          	cout<<-1<<endl;
            continue;
        }
        else
        {
            sort(a,a+n,cmp2);
            for(int i=0;i<n;i++)
                cout<<a[i].ans<<" ";
			cout<<endl;
        }
    }
    return 0;
}