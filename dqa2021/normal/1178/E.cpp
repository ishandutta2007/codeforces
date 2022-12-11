#include<cstdio>
#include<cstring>

char s[1000010]; int len;
bool mrk[1000010];
int main()
{
	scanf("%s",s+1); len=strlen(s+1);
	
//	printf("%d\n",len);   //debug !!!
	
	if (!(len&1)&&((len>>1)&1)) s[len--]=0;
	if (len&1)
	{
		int mid=len+1>>1;
		mrk[mid]=true;
		for (int i=1;i+1<mid;i+=2)
		{
			if (s[mid-i]==s[mid+i]) mrk[mid-i]=mrk[mid+i]=true;
			else if (s[mid-i]==s[mid+i+1]) mrk[mid-i]=mrk[mid+i+1]=true;
			else if (s[mid-i-1]==s[mid+i+1]) mrk[mid-i-1]=mrk[mid+i+1]=true;
			else mrk[mid-i-1]=mrk[mid+i]=true;
		}
		for (int i=1;i<=len;i++) if (mrk[i]) putchar(s[i]);
		putchar('\n');
		return 0;
	}
	int mid=len>>1;
	for (int i=1;i<mid;i+=2)
	{
		//mid-i mid-i+1    mid+i mid+i+1
		if (s[mid-i]==s[mid+i]) mrk[mid-i]=mrk[mid+i]=true;
		else if (s[mid-i]==s[mid+i+1]) mrk[mid-i]=mrk[mid+i+1]=true;
		else if (s[mid-i+1]==s[mid+i]) mrk[mid-i+1]=mrk[mid+i]=true;
		else mrk[mid-i+1]=mrk[mid+i+1]=true;
	}
	for (int i=1;i<=len;i++) if (mrk[i]) putchar(s[i]);
	putchar('\n');
	return 0;
}