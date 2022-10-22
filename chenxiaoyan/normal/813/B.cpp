/*








 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int inf=0x3f3f3f3f3f3f3f3f;
int a,b,l,r;
vector<int> v;
signed main(){
	cin>>a>>b>>l>>r;
	if(a==1)a=inf;if(b==1)b=inf;
	for(int i=1;;i*=a){
		for(int j=1;;j*=b){
			v.pb(i+j);
			if(r/j<b)break;
		}
		if(r/i<a)break;
	}
	sort(v.begin(),v.end());
	int lpos=0,rpos=v.size()-1;
	while(lpos<v.size()&&v[lpos]<l)lpos++;
	while(~rpos&&v[rpos]>r)rpos--;
	if(lpos>rpos)return cout<<r-l+1,0;
	int ans=max(v[lpos]-1-l+1,r-(v[rpos]+1)+1);
	for(int i=lpos;i<rpos;i++)ans=max(ans,v[i+1]-1-(v[i]+1)+1);
	cout<<ans;
	return 0;
}
/*1
2 3 1 10
*/
/*2
3 5 10 22
*/
/*3
2 3 3 5
*/