#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n;
string t;
int val[500005];
int book[500005][2],ans=0;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>t;
		int now=0,mn=0;
		for (int j=0;j<(int)t.size();j++){
			if (t[j]=='(')now++;
			else now--;
			mn=min(mn,now);
		}
		if (now<0&&mn==now)book[-now][0]++;
		if (now>=0&&mn>=0)book[now][1]++;
	}
	for (int i=1;i<=500000;i++)ans+=min(book[i][0],book[i][1]);
	ans+=book[0][1]/2;
	cout<<ans<<endl;
	return 0;
}