#include<iostream>
#include<vector>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
#define itr(type) type::iterator
map<char,vector<int> > poss;
const int inf=(1<<30)-1+(1<<30);
template<typename TYPE>
	void operator+=(vector<TYPE> &x,TYPE y)
	{
		x.push_back(y);
	}
vector<ll> ans;
int mem[150][100000];
bool memar[150][100000];
int fin(char aim,int pos,string &/**/s)
{
	if(poss[aim].empty())
		return s.size();
	if(memar[aim][pos])
		return mem[aim][pos];
	int mndif=inf;
	itr(vector<int>) beg=poss[aim].begin(),end=poss[aim].end();
	itr(vector<int>) lwb=lower_bound(beg,end,pos),upb=upper_bound(beg,end,pos)
	-1;
	if(lwb<end)
		mndif=*lwb-pos;
	if(upb>=beg)
		mndif=min(mndif,pos-*upb);
	memar[aim][pos]=true;
	return mem[aim][pos]=mndif;
}
int main()
{
	int n,len,i;
	string cor;
	cin>>n>>len>>cor;
	for(i=0;i<len;i++)
		poss[cor[i]]+=i;
	for(i=1;i<=n;i++)
	{
		string err;
		cin>>err;
		ll cost=0;
		for(int j=0;j<err.size();j++)
			cost+=fin(err[j],j,err);
		ans+=cost;
	}
	for(i=0;i<n;i++)
		cout<<ans[i]<<"\n";
	return 0;
}
/*1
2 10
codeforces
codeforces
codehorses
*/
/*2
9 9
vkontakte
vcontacte
vkontrakte
vkollapse
vkrokodile
vtopke
vkapuste
vpechke
vk
vcodeforcese
*/