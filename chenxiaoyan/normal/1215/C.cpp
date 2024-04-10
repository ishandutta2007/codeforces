/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=200000;
int n;
char a[N+5],b[N+5];
vector<int> ab,ba;
int main(){
	cin>>n>>a+1>>b+1;
	for(int i=1;i<=n;i++)
		if(a[i]=='a'&&b[i]=='b')ab.pb(i);
		else if(a[i]=='b'&&b[i]=='a')ba.pb(i);
	if(ab.size()+ba.size()&1)return puts("-1");
	cout<<ab.size()/2+(ba.size()/2)+(ab.size()&1)*2<<"\n";
	for(int i=0;i+1<ab.size();i+=2)cout<<ab[i]<<" "<<ab[i+1]<<"\n";
	for(int i=0;i+1<ba.size();i+=2)cout<<ba[i]<<" "<<ba[i+1]<<"\n";
	if(ab.size()&1)cout<<ab.back()<<" "<<ab.back()<<"\n"<<ab.back()<<" "<<ba.back();
	return 0;
}