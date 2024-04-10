#include<bits/stdc++.h>
using namespace std;
int h,w,cnt1[503],cnt2[503];
char c[503][503];
int main(){
	cin>>h>>w;
	for(int i=0;i<h;i++)for(int j=0;j<w;j++){cin>>c[i][j];if(c[i][j]=='*')cnt1[i]++,cnt2[j]++;}
	int cntx=0,cnty=0,x=0,y=0;
	for(int i=0;i<h;i++)if(cnt1[i]>1)cntx++,x=i;
	for(int i=0;i<w;i++)if(cnt2[i]>1)cnty++,y=i;
	if(cntx!=1||cnty!=1){
		cout<<"NO";
		return 0;
	}
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
			if(i!=x&&y!=j&&c[i][j]=='*')
			{
				cout<<"NO";
				return 0;
			}
	bool canx=1,cany=1;
	if(x==0||y==0||c[x][y]=='.'||c[x][y+1]=='.'||c[x][y-1]=='.'||c[x-1][y]=='.'||c[x+1][y]=='.'||x==h-1||y==w-1){
		cout<<"NO";
		return 0;
	}
	for(int i=x;i<h;i++)if(c[i][y]=='.')canx=0;else if(!canx){cout<<"NO";return 0;}
	canx=1;
	for(int i=x;i>=0;i--)if(c[i][y]=='.')canx=0;else if(!canx){cout<<"NO";return 0;}
	for(int i=y;i<w;i++)if(c[x][i]=='.')cany=0;else if(!cany){cout<<"NO";return 0;}
	cany=1;
	for(int i=y;i>=0;i--)if(c[x][i]=='.')cany=0;else if(!cany){cout<<"NO";return 0;}
	cout<<"YES";
}