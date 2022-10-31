#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <vector>
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x1 gtmsub
#define y1 gtmshb
#define x2 gtmjtjl
#define y2 gtmsf
using namespace std;
int n;
multiset<int> x1,x2,y1,y2;
struct node
{
	int x1,y1,x2,y2;
}a[210000];
int main()
{
	scanf("%d",&n);
	x1.clear();
	x2.clear();
	y1.clear();
	y2.clear();
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
		x1.insert(a[i].x1);
		x2.insert(a[i].x2);
		y1.insert(a[i].y1);
		y2.insert(a[i].y2);
	}
	for(int i=1;i<=n;i++)
	{
		auto it1=x1.find(a[i].x1); x1.erase(it1);
		auto it2=x2.find(a[i].x2); x2.erase(it2);
		auto it3=y1.find(a[i].y1); y1.erase(it3);
		auto it4=y2.find(a[i].y2); y2.erase(it4);
		
		auto it5=x1.end(); it5--; 
		int tmp1=*it5;
		int tmp2=*x2.begin();

		auto it6=y1.end(); it6--;
		int tmp3=*it6;
		int tmp4=*y2.begin();


		//cout<<tmp1<<" "<<tmp2<<" "<<tmp3<<" "<<tmp4<<endl;

		if (tmp1<=tmp2 && tmp3<=tmp4)
		{
			cout<<tmp1<<" "<<tmp3<<endl;
			return 0;
		}

		x1.insert(a[i].x1);
		x2.insert(a[i].x2);
		y1.insert(a[i].y1);
		y2.insert(a[i].y2);
	}
	return 0;
}