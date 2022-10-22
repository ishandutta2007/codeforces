#include<cstdio>
#include<string>
#include<vector>
#include<iostream>
const int N=1000001,Dx[8]={1,1,1,0,0,-1,-1,-1},Dy[8]={1,0,-1,1,-1,1,0,-1};
int n,m,qx[N],qy[N],l,r,qd[N];std::string s[N],ans[N];
std::vector<int>b[N];
inline bool Check(int g){
	int x,y,xx,yy;
	g=2*g+1;
	for(int i=0;i<n;i++)
	  for(int j=0;j<m;j++)ans[i][j]='.';
	for(int i=g-1;i<n;i++)
	  for(int j=g-1;j<m;j++)
		if(b[i][j]-(i>=g?b[i-g][j]:0)-(j>=g?b[i][j-g]:0)+(i>=g&&j>=g?b[i-g][j-g]:0)==g*g)
		  ans[i-g/2][j-g/2]='X';//,g==5&&printf(" %d %d\n",i-g/2,j-g/2);
	//if(g==5)for(int i=0;i<n;i++)std::cout<<ans[i]<<std::endl;
	l=0,r=-1;
	for(int i=0;i<n;i++)
	  for(int j=0;j<m;j++)
		if(ans[i][j]=='X')
		  ++r,qx[r]=i,qy[r]=j,qd[r]=0;
	for(;l<=r;){
	  if(qd[l]==g/2)break;
	  x=qx[l],y=qy[l];
	  for(int k=0;k<8;k++){
		xx=x+Dx[k],yy=y+Dy[k];//printf("   %d %d  %d %d\n",x,y,xx,yy);
		if(xx>=0&&yy>=0&&xx<n&&yy<m&&ans[xx][yy]=='.')
		  ++r,qx[r]=xx,qy[r]=yy,qd[r]=qd[l]+1,ans[xx][yy]='X';
	  }
	  l++;
	}
	//if(g==5)for(int i=0;i<n;i++)std::cout<<ans[i]<<std::endl;
	for(int i=0;i<n;i++)
	  for(int j=0;j<m;j++)if(s[i][j]!=ans[i][j])return 0;
	return 1;
}
int main(){
	int l,r,md;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)std::cin>>s[i];
	for(int i=0;i<n;i++)
	  for(int j=0;j<m;j++)b[i].push_back(s[i][j]=='X');
	for(int i=0;i<n;i++)
	  for(int j=0;j<m;j++)ans[i].push_back('.');
	for(int i=0;i<n;i++)
	  for(int j=0;j<m;j++)b[i][j]+=(i?b[i-1][j]:0)+(j?b[i][j-1]:0)-(i&&j?b[i-1][j-1]:0);
	for(l=0,r=std::min(n,m)-1>>1;l<r;)md=l+r+1>>1,Check(md)?l=md:r=md-1;//,printf("%d %d\n",l,r);
	printf("%d\n",r);
	r=2*r+1;
	for(int i=0;i<n;i++)
	  for(int j=0;j<m;j++)ans[i][j]='.';
	for(int i=r-1;i<n;i++)
	  for(int j=r-1;j<m;j++)
		if(b[i][j]-(i>=r?b[i-r][j]:0)-(j>=r?b[i][j-r]:0)+(i>=r&&j>=r?b[i-r][j-r]:0)==r*r)
		  ans[i-r/2][j-r/2]='X';
	//printf("%d %d\n",n,m);
	for(int i=0;i<n;i++){for(int j=0;j<m;j++)putchar(ans[i][j]);puts("");}
	return 0;
}