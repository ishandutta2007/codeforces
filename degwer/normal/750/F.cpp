#include<stdio.h>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;
vector<int>dat[128];
int cnt;
void get(int t)
{
	cnt++;
	if(cnt>16)
	{
		int x=0;
		for(int i=0;;i++)x++;
	}
	printf("? %d\n",t);fflush(stdout);
	int n;
	scanf("%d",&n);
	if(n==0)abort();
	vector<int>r;
	for(int i=0;i<n;i++)
	{
		int z;
		scanf("%d",&z);
		if(z==0)abort();
		r.push_back(z);
	}
	dat[t]=r;
}
void answer(int n)
{
	printf("! %d\n",n);fflush(stdout);
}
int unv(int n)
{
	if(dat[n].size()==1)return dat[n][0];
	for(int i=0;i<3;i++)if(dat[dat[n][i]].empty())return dat[n][i];
	//abort();
}
void solve()
{
	cnt=0;
	int num;
	scanf("%d",&num);
	if(num==0)abort();
	for(int i=0;i<128;i++)dat[i].clear();
	get(1);
	if(dat[1].size()==2)
	{
		answer(1);
		return;
	}
	int top;
	vector<int>vec;
	if(dat[1].size()==3)
	{
		deque<int>zd;
		zd.push_back(1);
		int now=1;
		for(;;)
		{
			now=unv(now);
			get(now);
			zd.push_back(now);
			if(dat[now].size()==2)
			{
				answer(now);
				return;
			}
			if(dat[now].size()==1)break;
		}
		now=1;
		for(;;)
		{
			now=unv(now);
			get(now);
			zd.push_front(now);
			if(dat[now].size()==2)
			{
				answer(now);
				return;
			}
			if(dat[now].size()==1)break;
		}
		top=zd[zd.size()/2];
		for(int i=0;i<=zd.size()/2;i++)vec.push_back(zd[i]);
	}
	else top=1,vec.push_back(1);
	for(;;)
	{
		vector<int>zv=vec;
		int now=top;
		bool f=false;
		for(int i=0;i<num-vec.size();i++)
		{
			now=unv(now);
			get(now);
			zv.push_back(now);
			if(dat[now].size()==2)
			{
				answer(now);
				return;
			}
			if(dat[now].size()==1)
			{
				f=true;
				break;
			}
		}
		if(f)
		{
			top=zv[zv.size()/2];
			vec.clear();
			for(int i=0;i<=zv.size()/2;i++)vec.push_back(zv[i]);
		}
		else
		{
			for(int i=0;i<zv.size();i++)
			{
				if(i+i+1<=num)continue;
				int t=num-i-1;
				if(t==1)
				{
					int x=unv(zv[i]);
					answer(x);
					return;
				}
				if(t==2)
				{
					int x=unv(zv[i]);
					get(x);
					if(dat[x].size()==2)
					{
						answer(x);
						return;
					}
					int y=unv(x);
					get(y);
					if(dat[y].size()==2)
					{
						answer(y);
						return;
					}
					int z=unv(x);
					get(z);
					if(dat[z].size()==2)
					{
						answer(z);
						return;
					}
				}
			}
		}
	}
}
int main()
{
	int data;
	scanf("%d",&data);
	for(int p=0;p<data;p++)
	{
		solve();
	}
}