//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//
//int n;
//char s[100010];
//int dp1[100010][26],dp2[100010][2][2];
//int dp3[100010];   //dp2  0 0 lcol  0 1 ltot   1 0 rcol   1 1 rtot
//int lent[100010];   //lent  len
//int main()
//{
//	scanf("%d",&n);
//	int len; scanf("%s",s+1); len=strlen(s+1);
//	bool flg=true;
//	for (int i=2;i<len;i++) if (s[i]!=s[i-1]) {flg=false; break;}
//	dp3[1]=(flg?s[1]-'a':-1);
//	for (int i=2;i<=n;i++)
//	{
//		scanf("%s",s+1); len=strlen(s+1);
//		lent[i]=len*(lent[i-1]+2);
//		flg=true;
//		for (int j=2;j<len;j++) if (s[j]!=s[j-1]) {flg=false; break;}
//		dp3[i]=(flg&&~dp3[i-1]?s[1]-'a':-1);
//		dp2[i][0][0]=dp2[i][1][0]=s[1]-'a';
//		if (~dp3[i])
//		{
//			dp2[i][0][1]=dp2[i][1][1]=lent[i];
//		}
//		else
//		{
////			dp[i][0][0]=
//			if (!flg)
//			{
//				for (dp2[i][0][1]=2;dp2[i][0][1]<=len&&s[dp2[i][0][1]]==s[dp2[i][0][1]-1];dp2[i][0][1]++);
//				dp2[i][0][1]--;
//			}
//			else
//			{
//				dp2[i][0][1]=len;
//				if (dp2[i-1][0][0]==dp2[i][0][0]) dp2[i][0][1]+=dp2[i-1][0][1];
//			}
//			
//			if (!flg)
//			{
//				for (int j=len-1;j&&s[j]==s[j+1];j--,dp2[i][1][1]++);
////				dp2[i][0][1]--;
//			}
//			else
//			{
//				dp2[i][1][1]=len;
//				if (dp2[i-1][1][0]==dp2[i][1][0]) dp2[i][1][1]+=dp2[i-1][1][1];
//			}
//		}
//		if (dp3[i])
//		{
//			dp1[i][s[1]]=len[i];
//		}
//		else
//		{
//			for (int j=0;i<26;i++)
//			{
//				dp1[i][j]=max(dp1[i-1][j]);
//			}
//		}
//	}
//}


#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;

int n,len; char s[100010];
int dp[2][26],g[26],h[4];
bool dpcur=false;
int main()
{
	scanf("%d%s",&n,s+1); len=strlen(s+1);
	for (int i=1,lst=1;i<=len;i++)
		if (i==len||s[i+1]!=s[i]) dp[dpcur][s[i]-'a']=max(dp[dpcur][s[i]-'a'],i-lst+1),lst=i+1;
	for (int i=2,j,lst;i<=n;i++)
	{
		dpcur^=1;
		memset(dp[dpcur],0,sizeof dp[dpcur]);
		memset(g,0,sizeof g);
//		memset(h,0,sizeof h);
		scanf("%s",s+1); len=strlen(s+1);
		for (j=1,lst=1;j<=len;j++)
			if (j==len||s[j+1]!=s[j]) g[s[j]-'a']=max(g[s[j]-'a'],j-lst+1),lst=j+1;
		h[0]=s[1]-'a'; h[2]=s[len]-'a';
		for (j=2;j<=len&&s[j]==s[1];j++);
		h[1]=j-1;
		for (j=len-1;j&&s[j]==s[len];j--);
		h[3]=len-j;
		if (h[1]==len)
		{
			for (j=0;j<26;j++)
				if (j==h[0]) dp[dpcur][j]=min(((ll)dp[dpcur^1][j]+1)*len+dp[dpcur^1][j],0x7fffffffLL);
				else dp[dpcur][j]=(dp[dpcur^1][j]?1:0);
			continue;
		}
		if (h[0]==h[2])
		{
			for (j=0;j<26;j++)
				if (j==h[0]) dp[dpcur][j]=max(g[j],(dp[dpcur^1][j]?h[1]+h[3]+1:0));
				else dp[dpcur][j]=max(g[j],(dp[dpcur^1][j]?1:0));
			continue;
		}
		for (int j=0;j<26;j++)
			if (j==h[0]) dp[dpcur][j]=max(g[j],(dp[dpcur^1][j]?h[1]+1:0));
			else if (j==h[2]) dp[dpcur][j]=max(g[j],(dp[dpcur^1][j]?h[3]+1:0));
			else dp[dpcur][j]=max(g[j],(dp[dpcur^1][j]?1:0));
	}
	for (int i=1;i<26;i++) dp[dpcur][0]=max(dp[dpcur][0],dp[dpcur][i]);
	printf("%d\n",dp[dpcur][0]);
	return 0;
}