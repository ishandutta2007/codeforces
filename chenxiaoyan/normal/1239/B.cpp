/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define X first
#define Y second
#define pb push_back
const int inf=0x3f3f3f3f;
void prt(pair<int,pair<int,int> > x){cout<<x.X<<"\n"<<x.Y.X<<" "<<x.Y.Y<<"\n";}
const int N=300000;
int n;
string a;
int Bal[N+1];
int Mn[N+1],mN[N+2];
int ori(int x,int y){
	return x<=n-y+1?x+y-1:x-(n-y+1);
}
int main(){
	cin>>n>>a;a=(string)" "+a;
	for(int i=1;i<=n;i++)Bal[i]=Bal[i-1]+(a[i]=='('?1:-1);
	Mn[0]=mN[N+1]=inf;
	for(int i=1;i<=n;i++)Mn[i]=min(Mn[i-1],Bal[i]);
	for(int i=n;i;i--)mN[i]=min(mN[i+1],Bal[i]);
	for(int i=1;i<=n;i++)if(mN[i]-Bal[i-1]>=0&&Mn[i-1]+Bal[n]-Bal[i-1]>=0&&Bal[n]==0){
		a=(string)" "+a.substr(i,n-i+1)+a.substr(1,i-1);
//		cout<<a<<"\n";
		stack<int> stk;
		vector<pair<pair<int,int>,vector<pair<pair<int,int>,int> > > > v;
		for(int j=1;j<=n;)if(a[j]=='('&&stk.empty()){
			vector<pair<pair<int,int>,int> > vv;
			int cnt=0;
			for(int k=j;;k++){
				if(a[k]=='(')cnt+=stk.size()==2,stk.push(k);
				else stk.size()==2?vv.pb(mp(mp(stk.top(),k),cnt)),cnt=0:0,stk.pop();
				if(stk.empty()){v.pb(mp(mp(j,k),vv));j=k+1;break;}
			}
		}
//		for(int j=0;j<v.size();j++)cout<<v[j].X.X<<" "<<v[j].X.Y<<" "<<v[j].Y.size()<<"\n";
		pair<int,pair<int,int> > ans1=mp(v.size(),mp(1,1)),ans2=mp(0,mp(0,0)),ans3=ans2;
		for(int j=0;j<v.size();j++){
			ans2=max(ans2,mp((int)v[j].Y.size()+1,mp(ori(v[j].X.X,i),ori(v[j].X.Y,i))));
			int mx=0;pair<int,int> mxid=mp(1,1);
			for(int k=0;k<v[j].Y.size();k++)
				if(v[j].Y[k].Y>=mx)mx=v[j].Y[k].Y,mxid=v[j].Y[k].X;
			if(v[j].Y.size())ans3=max(ans3,mp((int)v.size()+1+mx,mp(ori(mxid.X,i),ori(mxid.Y,i))));
		}
//		prt(ans1);prt(ans2);prt(ans3);puts("");
		pair<int,pair<int,int> > ans=max(max(ans1,ans2),ans3);
		prt(ans);
		return 0;
	}
	puts("0\n1 1");
	return 0;
}
/*1
4
))((
*///