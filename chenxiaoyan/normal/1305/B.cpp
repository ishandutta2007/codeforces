/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ppb pop_back
const int N=1000;
char a[N+5];
int main(){
	int n;
	cin>>a+1;
	n=strlen(a+1);
	vector<vector<int> > ans;
	while(true){
		vector<int> v;
		vector<int> pos1,pos2;
		for(int j=1;j<=n;j++)
			if(a[j]=='(')pos1.pb(j);
			else if(a[j]==')')pos2.pb(j);
		for(int j=0;j<pos1.size();j++){
			if(pos2.empty()||pos1[j]>pos2.back())break;
			v.pb(pos1[j]);v.pb(pos2.back());
			a[pos1[j]]=a[pos2.back()]=0;
			pos2.ppb();
		}
		if(v.empty())break;
		sort(v.begin(),v.end());
		ans.pb(v);
	}
	cout<<ans.size()<<"\n";
	for(int i=0;i<ans.size();i++){
		cout<<ans[i].size()<<"\n";
		for(int j=0;j<ans[i].size();j++)printf("%d ",ans[i][j]);
		puts("");
	}
	return 0;
}