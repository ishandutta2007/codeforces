#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define prt(n) cout<<(n)<<endl
#define elif else if
#define str string
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
const int N=55;
vector<string> names;
map<string,int> score;
map<string,int> takes[N];
const int sc[10]={25,18,15,12,10,8,6,4,2,1};
int getsc(int a)
{
	if(a>=10) return 0;
	return sc[a];
}
void input1()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string a;
		cin>>a;
		if(!count(names.begin(),names.end(),a)) names.push_back(a);
		takes[i][a]++;
		score[a]+=getsc(i);
	}
}
bool is_first_bigger1(string a,string b)
{
	if(score[a]!=score[b]) return score[a]>score[b];
	for(int i=0;i<N;i++)
	{
		if(takes[i][a]!=takes[i][b]) return takes[i][a]>takes[i][b];
	}
	return 0;
}
bool is_first_bigger2(string a,string b)
{
	if(takes[0][a]!=takes[0][b]) return takes[0][a]>takes[0][b];
	if(score[a]!=score[b]) return score[a]>score[b];
	for(int i=1;i<N;i++)
	{
		if(takes[i][a]!=takes[i][b]) return takes[i][a]>takes[i][b];
	}
	return 0;
}
bool is_first_bigger(string a,string b,bool is2)
{
	if(is2)
	{
		return is_first_bigger2(a,b);
	}
	else
	{
		return is_first_bigger1(a,b);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int i=0;i<t;i++) input1();
	for(int i=0;i<2;i++)
	{
		string ans1=names[0];
		for(int j=1;j<names.size();j++)
		{
			if(is_first_bigger(names[j],ans1,i))
			ans1=names[j];
		}
		cout<<ans1<<endl;
	}
	return 0;
}