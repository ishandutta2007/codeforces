/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define X first
#define Y second
int gcd(int x,int y){return y?gcd(y,x%y):x;}
vector<pair<int,int> > v;
vector<int> now;
void dfs(int x,int num=1){
	if(x==v.size())return now.pb(num),void();
	for(int i=0;i<=v[x].X;i++,num*=v[x].Y){
		dfs(x+1,num);
	}
}
void mian(){
	int n;
	cin>>n;
	v.clear();
	for(int i=2;i*i<=n;i++)if(n%i==0){
		v.pb(mp(0,i));
		while(n%i==0)v.back().X++,n/=i;
	}
	if(n>1)v.pb(mp(1,n));
	sort(v.begin(),v.end());
	if(v.size()==2&&v[0].X==1&&v[1].X==1)return printf("%d %d %d\n%d\n",v[0].Y,v[1].Y,v[0].Y*v[1].Y,1),void();
	for(int i=0;i<v.size();i++){
		now.clear();
		dfs(i+1);
		vector<int> vv;
		for(int j=0;j<now.size();j++)for(int k=1,o=v[i].Y;k<=v[i].X;k++,o*=v[i].Y)vv.pb(now[j]*o);
		now=vv;
		for(int j=0;j<now.size();j++){
			if(i+1<v.size()&&now[j]==v[i].Y*v[i+1].Y)swap(now[j],now.back());
			if(i==0){
				if(v.size()==2&&now[j]==v[i].Y*v[1].Y*v[1].Y)swap(now[j],now[0]);
				if(v.size()>2&&now[j]==v[i].Y*v.back().Y)swap(now[j],now[0]);
			}
		}
		for(int j=0;j<now.size();j++)if(now[j])printf("%d ",now[j]);
	}
	puts("\n0");
}
int main(){
	int testnum=1;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}