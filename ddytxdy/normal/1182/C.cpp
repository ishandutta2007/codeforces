#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
const int N=1e5+50,M=1e6+50;
int n,d[127],l[M][6];
string c[N];
vector<pair<int,int> >fi,se;
void print(int x,int y,int z,int a){
	cout<<c[x]<<" "<<c[y]<<endl<<c[z]<<" "<<c[a]<<endl;
}
int main(){
	d['a']=1;d['e']=2;d['i']=3;d['o']=4;d['u']=5;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>c[i];
		int len=c[i].length(),tot=0,la;
		for(int j=0;j<len;j++)if(d[c[i][j]])tot++,la=d[c[i][j]];
		if(l[tot][la]){
			se.pb(mp(l[tot][la],i));      
			l[tot][la]=0;
		}
		else l[tot][la]=i;
	}
	for(int i=1;i<=1e6;i++){
		int la=0;
		for(int j=1;j<=5;j++){
			if(l[i][j]){
				if(la)fi.pb(mp(la,l[i][j])),la=0;
				else la=l[i][j];
			}
		}
	}
	while(fi.size()<se.size()){
		fi.pb(se.back());
		se.pop_back();
	}
	printf("%d\n",se.size());
	for(int i=0;i<se.size();i++)print(fi[i].first,se[i].first,fi[i].second,se[i].second);
	return 0;
}