#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<set>
#include<queue>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);++(i))
#define fd1(i,n) for ((i)=(n);(i)>=1;--(i))
#define fz0g(i,n) for ((i)=0;(i)<=(n);++(i))
#define fd0g(i,n) for ((i)=(n);(i)>=0;--(i))
#define fz0k(i,n) for ((i)=0;(i)<(n);++(i))
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;--(i))
#define fz(i,x,y) for ((i)=(x);(i)<=(y);++(i))
#define fd(i,y,x) for ((i)=(y);(i)>=(x);--(i))
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
using namespace std;
string st,tar;
int n,m,i,j,t;
vector<pair<int,int> > ans;
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>t; 
	while(t--)
	{
		cin>>n>>m;
		cin>>st;st=" "+st;
		tar=" ";
		fz1(i,m-1){
			tar+="()";
		}
		fz1(i,n/2-m+1){
			tar+="(";
		}
		fz1(i,n/2-m+1){
			tar+=")";
		}
		ans.clear();
		fz1(i,n){
			if(st[i]!=tar[i]){
				j=i;
				while(st[i]==st[j]) j++;
				swap(st[i],st[j]);
				ans.push_back(make_pair(i,j));
			}
		}
		cout<<ans.size()<<endl;
		ff(ans,it){
			cout<<it->first<<' '<<it->second<<endl;
		}
	}
	return 0;
}