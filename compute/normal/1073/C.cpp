#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	string s;
	cin>>s;
	int x,y;
	scanf("%d%d",&x,&y);
	int nowx=0,nowy=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='L')
			nowx--;
		else if(s[i]=='U')
			nowy++;
		else if(s[i]=='R')
			nowx++;
		else nowy--;
	}
	int ans=0x3f3f3f3f;
	int len;
	if(abs(x)+abs(y)>n||((abs(x)+abs(y))%2==0&&n%2!=0)||((abs(x)+abs(y))%2!=0&&n%2==0)) ans=-1;
	else{
		int right=-1,left=0;
		while(right!=n-1)
		{
			right++;
			len=right-left+1;
			if(s[right]=='L')
				nowx++;
			else if(s[right]=='R')
				nowx--;
			else if(s[right]=='U')
				nowy--;
			else nowy++;
			if(abs(x-nowx)+abs(y-nowy)>len) continue;
			while(left<=right)
			{
				int tempx=nowx,tempy=nowy;
				len=right-left;
				if(s[left]=='L')
					tempx--;
				else if(s[left]=='R')
					tempx++;
				else if(s[left]=='U')
					tempy++;
				else tempy--;
				if(abs(x-tempx)+abs(y-tempy)>len) break;
				nowx=tempx,nowy=tempy;
				left++;
			}
			len=right-left+1;
			//cout<<left<<", "<<right<<"  ,"<<len<<endl;
			ans=min(ans,len);
		}
	}
	printf("%d\n",ans);

}