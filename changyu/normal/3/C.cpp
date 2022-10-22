#include<cstdio>
const int Dx[8][3]={{0,0,0},{1,1,1},{2,2,2},{0,1,2},{0,1,2},{0,1,2},{0,1,2},{0,1,2}},Dy[8][3]={{0,1,2},{0,1,2},{0,1,2},{0,0,0},{1,1,1},{2,2,2},{0,1,2},{2,1,0}};
char a[3][4];int x,o;
inline bool Win(char x){
	int f;
	for(int i=0;i<8;i++){
	  f=1;
	  for(int k=0;k<3;k++)
		if(a[Dx[i][k]][Dy[i][k]]!=x){f=0;break;}
	  if(f)return 1;
	}
	return 0;
}
int main()
{
	x=o=0;
	for(int i=0;i<3;i++){
	  scanf("%s",a[i]);
	  for(int j=0;j<3;j++)x+=a[i][j]=='X',o+=a[i][j]=='0';
	}
	if(x-o>1||x-o<0||Win('X')&&x-o!=1||Win('0')&&x-o)return 0*puts("illegal");
	if(Win('X'))return 0*puts("the first player won");
	if(Win('0'))return 0*puts("the second player won");
	if(o+x==9)return 0*puts("draw");
	if(x==o)return 0*puts("first");
	return 0*puts("second");
}