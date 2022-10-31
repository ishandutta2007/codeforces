#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
bool same[maxn];
string str[maxn];
int mxlen[maxn];
int Count(int num,int type=0,char st='a')
{
	int ret=0;
	if(!type)
		for(int i=0;i<str[num].length()&&str[num][i]==st;i++) ret++;
	else for(int i=str[num].length()-1;i>=0&&str[num][i]==st;i--) ret++;
	return ret;
}
int main()
{
	int len=0;
	char st,ed;
	int stlen=0,edlen=0;
	bool single=1;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>str[i];
		bool ok=1;
		int cur=1;
		mxlen[i]=1;
		for(int j=1;j<str[i].length();j++)
		{
			if(str[i][j]!=str[i][j-1]) ok=0,cur=1;
			else cur++;
			mxlen[i]=max(mxlen[i],cur);
		}
		same[i]=ok;
	}
	st=str[n-1][0];
	ed=str[n-1][str[n-1].length()-1];
	stlen=Count(n-1,0,st);
	edlen=Count(n-1,1,ed);
	len=mxlen[n-1];
	single=same[n-1];
	for(int i=n-2;i>=0;i--)
	{
		if(single&&same[i])
		{
			if(st==str[i][0])
			{
				len=len*(str[i].length()+1)+str[i].length();
				stlen=edlen=len;
			}
			else{
				single=0;
			}
		}
		else{
			if(single)
			{
				int cnt=0;
				int cont=0,stcont=0,edcont=0;
				for(int j=0;j<str[i].length();j++)
				{
					if(str[i][j]==st) cnt++;
					else cnt=0;
					cont=max(cont,cnt);
				}
				len=(cont+1)*len+cont;
				int cntst=Count(i,0,st),cnted=Count(i,1,st);
				stlen=(cntst+1)*stlen+cntst;
				edlen=(cnted+1)*edlen+cnted;
			}
			else{
				int nxt=0;
				for(int j=0;j<str[i].length();j++)
				{
					char cur=str[i][j];
					if(cur==st&&cur==ed)
					{
						nxt=stlen+edlen+1;
						break;
					}
					else if(cur==st)
						nxt=max(nxt,stlen+1);
					else if(cur==ed)
						nxt=max(nxt,edlen+1);
				}
				len=max(len,nxt);
			}
			single=0;
		}
	}
	printf("%d\n",len);
}