#include<bits/stdc++.h>
typedef long long LL;
const int bel[4][5]={{0,0,0,0,0},{0,1,2,3,4},{0,1,3,4,2},{0,1,4,2,3}};
inline LL Calc(LL line,LL row,LL bg,LL ed)
{
	#ifdef Dubug
	printf("Calc(%lld,%lld,%lld,%lld);\n",line,row,bg,ed);
	#endif 
	if(bg==ed)return bg;
	LL p=ed-bg+1,len=p/4;
	LL block=(row-1)/len+1;
	#ifdef Dubug
	printf("block=%lld\n",block);
	#endif
	row=(row-1)%len+1;
	LL _bg=bg+(bel[line][block]-1)*len;
	return Calc(line,row,_bg,_bg+len-1);
}
inline void Solve()
{
	LL n,row,line;
	scanf("%lld",&n);
	row=(n-1)/3+1;
	line=n-3*(row-1);
	for(LL _row=0,sum=0,size=1;;size*=4)
	{
		if(row<=_row+size)
		{
			printf("%lld\n",Calc(line,row-_row,sum+(line-1)*size+1,sum+line*size));
			return;
		}
		_row+=size;sum+=size*3; 
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)Solve();
	return 0;
}