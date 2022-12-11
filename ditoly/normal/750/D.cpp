#include<cstdio>
const int o[8][2]={{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
int f[305][305],qx[31][100000],qy[31][100000],qt[31][100000],qn[31],mp[31][8][305][305],ans;
int main()
{
	int n,i,j,k,t,xx,yy,tt;
	scanf("%d",&n);
	qn[0]=1;qx[0][0]=150;qy[0][0]=150;qt[0][0]=3;
	for(i=1;i<=n;++i)
	{
		scanf("%d",&t);
		for(j=0;j<qn[i-1];++j)
		{
			xx=qx[i-1][j];yy=qy[i-1][j];tt=qt[i-1][j];
			for(k=0;k<t;++k)
			{
				xx+=o[tt][0];yy+=o[tt][1];
				if(!f[xx][yy])f[xx][yy]=1,++ans;
			}
			--tt;if(tt<0)tt+=8;
			if(!mp[i][tt][xx][yy])
				mp[i][tt][xx][yy]=1,qx[i][qn[i]]=xx,qy[i][qn[i]]=yy,qt[i][qn[i]]=tt,++qn[i];
			tt+=2;if(tt>7)tt-=8;
			if(!mp[i][tt][xx][yy])
				mp[i][tt][xx][yy]=1,qx[i][qn[i]]=xx,qy[i][qn[i]]=yy,qt[i][qn[i]]=tt,++qn[i];
		}
	}
	printf("%d",ans);
}