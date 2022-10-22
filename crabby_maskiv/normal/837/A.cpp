#include<iostream>
#include<cstring> 
using namespace std;
char a[205];
int cnt,mxcnt;
int main()
{
	int tmp;cin>>tmp;
	getchar();
	cin.getline(a,205,'\n');
	int i,l=strlen(a);
	for(i=0;i<l;i++)
	{
		if(a[i]>='A'&&a[i]<='Z') cnt++;
		if(cnt>mxcnt) mxcnt=cnt;
		if(a[i]==' ') cnt=0;
	}
	cout<<mxcnt;
	return 0;
}