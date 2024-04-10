/*








 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int N=2000;
int n;
int a[N+1];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	set<int> s;
	int ans=n-1;
	for(int i=0;i<=n;i++){
		if(i){
			int szz=s.size();
			s.insert(a[i]);
			if(s.size()!=szz+1)break;
		}
		set<int> cpy=s;
		for(int j=n+1;j>i;j--){
			if(j<=n){
				int sz=s.size();
				s.insert(a[j]);
				if(s.size()!=sz+1)break;
			}
			ans=min(ans,(j-1)-(i+1)+1);
		}
		s=cpy;
	}
	cout<<ans<<"\n";
	return 0;
}