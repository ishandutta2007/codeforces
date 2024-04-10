#include<cstdio>
#include<bitset>
#include<cstring>
using namespace std;
const int N=1e5+10;
bitset<N>b[26],ans;
char s[N],str[N],c;
int op,n,w,x,y,len,Q;
int main()
{
	scanf("%s%d",s,&Q);
	n=strlen(s);
	for(int i=0;i<n;i++)
		b[s[i]-'a'][i]=1;
	while(Q--)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d %c",&w,&c),w--;
			b[s[w]-'a'][w]=0,s[w]=c;
			b[c-'a'][w]=1;
		}
		else
		{
			scanf("%d%d%s",&x,&y,str),x--,y--;
			len=strlen(str);
			if(y-x+1<len){printf("0\n");continue;}
			ans.set();
			for(int i=0;i<len;i++)
				ans=ans&(b[str[i]-'a']>>i);
			printf("%d\n",(ans>>x).count()-(ans>>(y-len+2)).count());
		}
	}
}