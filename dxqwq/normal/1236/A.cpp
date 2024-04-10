
 #include<bits/stdc++.h>
using namespace std;
int qwq()
{
	int a,b,c,ans;
	cin>>a>>b>>c;
	if(b==0) return 0&printf("0\n");
	ans=min(b,c/2);
	b-=min(b,c/2);
	ans+=min(a,b/2);
	printf("%d\n",ans*3);
	return 0;
}
int main()
{
	int T;
	cin>>T;
	while(T--) qwq();
}