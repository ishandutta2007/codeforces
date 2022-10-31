#include<bits/stdc++.h>
#define int long long
const int N=505;
using namespace std;

int n,m;
int fl[N][N];
char a[N][N],b[N][N],C[N][N],ty1,ty2;
int cnt0[N],cnt1[N];
int x,y,_x,_y;

bool check(int x,int y){
	if(x+2>n)return 0;
	if(y+2>m)return 0;
	int c0=0,c1=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++){
			c0+=!cnt0[a[x+i][y+j]];
			c1+=!cnt1[b[x+i][y+j]];
			cnt0[a[x+i][y+j]]++;
			cnt1[b[x+i][y+j]]++;
		}
	int ans=(c0==1)||(c1==9);
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++){
			cnt0[a[x+i][y+j]]--;
			cnt1[b[x+i][y+j]]--;
		}
	return ans;
}

bool check2(int a,int b,int c,int d){
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			C[c+i][d+j]++;
	int ans=1;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(C[a+i][b+j]==1)
				ans=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			C[c+i][d+j]--;
	return ans;
}

void solve0(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(check(i,j))
				for(int k=1;k<=n;k++)
					for(int l=1;l<=m;l++)
						if(check(k,l))
							if(check2(i,j,k,l)){
								printf("Solution exists.\n");
								printf("There are no jokers.\n");
								printf("Put the first square to (%d, %d).\n",i,j);
								printf("Put the second square to (%d, %d).\n",k,l);
								exit(0);
							}
	printf("No solution.\n"); 
}

vector<char> X={'C','D','H','S'},Y={'A','2','3','4','5','6','7','8','9','T','J','Q','K'}; 

void solve1(int x,int y){
	for(char _:X)
		for(char __:Y)
			if(!fl[_][__]){
				a[x][y]=_;
				b[x][y]=__;
				for(int i=1;i<=n;i++)
					for(int j=1;j<=m;j++)
						if(check(i,j))
							for(int k=1;k<=n;k++)
								for(int l=1;l<=m;l++)
									if(check(k,l))
										if(check2(i,j,k,l)){
											printf("Solution exists.\n");
											printf("Replace J%c with %c%c.\n",ty1,__,_);
											printf("Put the first square to (%d, %d).\n",i,j);
											printf("Put the second square to (%d, %d).\n",k,l);
											exit(0);
										}
			}
	printf("No solution.\n"); 
}

void solve2(int x,int y,int _x,int _y){
	if(ty1=='2')swap(x,_x),swap(y,_y);
	for(char _:X)
		for(char __:Y)
			if(!fl[_][__]){
				a[x][y]=_;
				b[x][y]=__;
				for(char ___:X)
					for(char ____:Y)
						if(!fl[___][____])
							if(_!=___||__!=____){
								a[_x][_y]=___;
								b[_x][_y]=____;
								for(int i=1;i<=n;i++)
									for(int j=1;j<=m;j++)
										if(check(i,j))
											for(int k=1;k<=n;k++)
												for(int l=1;l<=m;l++)
													if(check(k,l))
														if(check2(i,j,k,l)){
															printf("Solution exists.\n");
															printf("Replace J1 with %c%c and J2 with %c%c.\n",__,_,____,___);
															printf("Put the first square to (%d, %d).\n",i,j);
															printf("Put the second square to (%d, %d).\n",k,l);
															exit(0);
														}}
			}
	printf("No solution.\n"); 
}

void solve(){
	cin>>n>>m;
	int cnt=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>b[i][j]>>a[i][j];
			fl[a[i][j]][b[i][j]]=1;
			if(b[i][j]=='J'&&(a[i][j]=='1'||a[i][j]=='2')){
				if(cnt)_x=i,_y=j,ty2=a[i][j];
				else x=i,y=j,ty1=a[i][j];
				++cnt;
			}
		}
	if(cnt==0)solve0();
	if(cnt==1)solve1(x,y);
	if(cnt==2)solve2(x,y,_x,_y);
}

main(){
	int _T=1;//cin>>_T;
	while(_T--)solve();
}