/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=100000,X=3001;
int n;
int x1[N+1],y1[N+1],x2[N+1],y2[N+1];
int Sum[X+1][X+1];
int Bd_r[X+2][X+1],Bd_c[X+2][X+1];
vector<int> lft[X+1];
int cmp(int x,int y){return x1[x]<x1[y];}
bool chk(int a,int b,int c,int d){
	if(a<=0||b<=0||c<=0||d<=0||a>X||b>X||c>X||d>X)return false;
	if(Sum[c][d]-Sum[a-1][d]-Sum[c][b-1]+Sum[a-1][b-1]<(c-a+1)*(d-b+1))return false;
	if(Bd_r[a][d]-Bd_r[a][b-1]<d-b+1)return false;
	if(Bd_r[c+1][d]-Bd_r[c+1][b-1]<d-b+1)return false;
	if(Bd_c[b][c]-Bd_c[b][a-1]<c-a+1)return false;
	if(Bd_c[d+1][c]-Bd_c[d+1][a-1]<c-a+1)return false;
	return true;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d%d",x1+i,y1+i,x2+i,y2+i);
		x1[i]++,y1[i]++;
		for(int j=x1[i];j<=x2[i];j++)for(int k=y1[i];k<=y2[i];k++)Sum[j][k]=1;
		for(int j=y1[i];j<=y2[i];j++)Bd_r[x1[i]][j]=Bd_r[x2[i]+1][j]=1;
		for(int j=x1[i];j<=x2[i];j++)Bd_c[y1[i]][j]=Bd_c[y2[i]+1][j]=1;
		lft[y1[i]].pb(i);
	}
	for(int i=1;i<=X;i++)for(int j=1;j<=X;j++)Sum[i][j]+=Sum[i-1][j]+Sum[i][j-1]-Sum[i-1][j-1];
//	for(int i=1;i<=10;i++){for(int j=1;j<=10;j++)cout<<Sum[i][j]<<" ";puts("");}
	for(int i=1;i<=X+1;i++)for(int j=1;j<=X;j++)Bd_r[i][j]+=Bd_r[i][j-1],Bd_c[i][j]+=Bd_c[i][j-1];
	for(int i=1;i<=X;i++){
		sort(lft[i].begin(),lft[i].end(),cmp);
		for(int j=0;j<lft[i].size();j++)for(int k=j;k<lft[i].size();k++){
			int a=x1[lft[i][j]],b=y1[lft[i][j]],c=x2[lft[i][k]],d=b-a+c;
			if(chk(a,b,c,d)){
				printf("YES ");
				vector<int> ans;
				for(int o=1;o<=n;o++)if(a<=x1[o]&&x1[o]<=c&&b<=y1[o]&&y1[o]<=d)ans.pb(o);
				cout<<ans.size()<<"\n";
				for(int o=0;o<ans.size();o++)cout<<ans[o]<<" ";
				return 0;
			}
		}
	}
	puts("NO");
	return 0;
}