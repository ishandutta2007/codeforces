#include<cstdio>
#include<cstdlib>
#include<map>
#include<string>

using namespace std;

int main()
{
map<string,int> check;
check["ABSINTH"]=check["BEER"]=check["BRANDY"]=check["CHAMPAGNE"]=
check["GIN"]=check["RUM"]=check["SAKE"]=check["TEQUILA"]=
check["VODKA"]=check["WHISKEY"]=check["WINE"]=1;

char a[200];
gets(a);
int n,t,c=0;
n=atoi(a);

while(n--)
{
gets(a);
if(a[0]>='0'&&a[0]<='9')
{t=atoi(a);if(t<18) c++;}
else
if(check[a]==1) c++;
}
printf("%d\n",c);
//scanf("%d\n",&n);
}