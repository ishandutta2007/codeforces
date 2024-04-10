#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
int fat[49];
int ance(int x){return fat[x]==x?x:fat[x]=ance(fat[x]);}
void merge(int x,int y){fat[ance(x)]=ance(y);}
vector<int> one;vector<pair<int,int> > two;vector<pair<int,pair<int,int> > > three;
int X(pair<int,int> x){return x.first;}int Y(pair<int,int> x){return x.second;}
int X(pair<int,pair<int,int> > x){return x.first;}int Y(pair<int,pair<int,int> > x){return x
.second.first;}int Z(pair<int,pair<int,int> > x){return x.second.second;}
pair<int,pair<int,int> > mp(int x,int y,int z){return mp(x,mp(y,z));}
int main(){
	int n,m,i;scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)fat[i]=i;
	for(i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		merge(x,y);
	}
	for(i=1;i<=n;i++)if(fat[i]==i){
		vector<int> x;
		for(int j=1;j<=n;j++)if(ance(j)==i)x.pb(j);
		if(x.size()>3)return !printf("-1");
		if(x.size()==3)three.pb(mp(x[0],x[1],x[2]));
		else if(x.size()==2)two.pb(mp(x[0],x[1]));
		else one.pb(i);
	}
//	printf("%d %d %d\n",one.size(),two.size(),three.size());
	if(two.size()>one.size())return !printf("-1");
	if((one.size()-two.size())%3)return !printf("-1");
	for(i=0;i<three.size();i++)printf("%d %d %d\n",X(three[i]),Y(three[i]),Z(three[i]));
	for(i=0;i<two.size();i++)printf("%d %d %d\n",one[i],X(two[i]),Y(two[i]));
	for(i=two.size();i<one.size();i+=3)printf("%d %d %d\n",one[i],one[i+1],one[i+2]);
	return 0;
}
/*1
3 0
*/
/*2
6 4
1 2
2 3
3 4
5 6
*/
/*3
3 3
1 2
2 3
1 3
*/