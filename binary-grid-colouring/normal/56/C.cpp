#include<bits/stdc++.h>
using namespace std;
char s[1010];
char s1[1010],s2[1010];
int main()
{
	int ans=0;int cnt=0;
	scanf("%s",s);
	for(int i=0;s[i];i++)
	{
		if(s[i]<'A' || s[i]>'Z')
		{
			//puts(s1);
			if(s[i]==':')
			{
				int n1=0;
				int tmp=1;
				s1[cnt]=0;
				for(int j=i+1;s[j];j++)
				{
					if(tmp==0)break;
					if(s[j]==':')tmp++;
					if(s[j]=='.' && s[j-1]=='.')tmp--;
					if(s[j]<'A' || s[j] > 'Z')
					{
						s2[n1]=0;
						
						if(strcmp(s2,s1)==0)
						{
							//puts(s1); 
							//puts(s2);
							ans++;
						}
						n1=0;
					}
					else{
						s2[n1] = s[j];
						n1++;
					}
				}
			}
				
			cnt=0;
		}
		else
		{
			s1[cnt] = s[i] ;
			cnt++;
		}
	}
	cout<<ans<<endl;
    return 0;
}