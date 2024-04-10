#include<iostream>
#include<stack>
#include<algorithm>
#include<cstring>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=1e5+7;
string s;
struct node{
	int l,r;
}arr[maxn];
int ls[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		stack<char> st;
		for(int j=0;j<s.length();j++)
		{
			if(s[j]==')')
			{
				if(!st.empty()&&st.top()=='(')
					st.pop();
				else st.push(')');
			}
			else st.push('(');
		}
		arr[i].l=arr[i].r=0;
		while(!st.empty())
		{
			if(st.top()=='(') arr[i].l++;
			else arr[i].r++;
			st.pop();
		}
		ls[i]=arr[i].l-arr[i].r;
		if(arr[i].l&&arr[i].r) ls[i]=INF;
	}
	int ans=0;
	sort(ls,ls+n);
	int l=0,r=n-1;
	while(l<r)
	{
		if(ls[l]+ls[r]==0){
			ans++;
			l++,r--;
		}
		else if(ls[l]+ls[r]>0)
		{
			r--;
		}
		else{
			l++;
		}
	}
	cout<<ans<<endl;
}