#include<bits/stdc++.h>

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

const int N=1e6+5;
int n,m,mmap[5][N],ans;
// n<=m 3
char s[N];

inline int get_2_ans(int x);
// n=2 x 
  
inline int get_3_ans(int x,int y);
// n=3 x y 

int main()
{
	n=read();m=read();
	if(n>=4)
		printf("-1\n");
	else if(n==1)
		printf("0\n");
	else if(n==2) //n==2 
	{
		for(int i=1;i<=n;++i)
		{
			scanf("%s",s+1);
			for(int j=1;j<=m;++j)
				mmap[i][j]=s[j]-'0';
		}
		ans=min(get_2_ans(0),get_2_ans(1));
		printf("%d\n",ans);
	}
	else //n==3 
	{
		for(int i=1;i<=n;++i)
		{
			scanf("%s",s+1);
			for(int j=1;j<=m;++j)
				mmap[i][j]=s[j]-'0';
		}
		ans=0x7fffffff;
 		//
		ans=min(ans,get_3_ans(0,0));
		ans=min(ans,get_3_ans(1,0));
		ans=min(ans,get_3_ans(0,1));
		ans=min(ans,get_3_ans(1,1));
		printf("%d\n",ans); 
	}
	return 0;
} 

inline int get_2_ans(int x)
{
	int res=0;
	for(int i=1;i<=m;++i)
	{
        //   
		if((mmap[1][i]+mmap[2][i])%2!=x)
			res++;
		x=!x;  //  
	}
	return res;
}

inline int get_3_ans(int x,int y)
{
	int res=0;
	for(int i=1;i<=m;++i)
	{
		//  
		if((mmap[1][i]+mmap[2][i])%2!=x)
			res++;
		else if((mmap[2][i]+mmap[3][i])%2!=y)
			res++;
		x=!x;y=!y;  //  
	}
	return res;
}