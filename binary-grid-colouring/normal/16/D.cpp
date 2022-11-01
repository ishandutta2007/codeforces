#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char str[105];
int main()
{
    int n;
	cin>>n; 
    gets(str);
    int ans=1;
	int h=0,m=-1,cnt=1;
    for(int i=0;i<n;i++)
    {
        gets(str);
        int th=10*(str[1]-'0')+(str[2]-'0');
        int tm=10*(str[4]-'0')+(str[5]-'0');
        if(th == 12)th=0;
        if(str[7]=='p') th+=12;
        if(th < h || (th == h && tm < m)) ans++;
        if(th == h && tm == m) cnt++;
        else cnt=1;
        // [date:time]: message, where for each [date:time] value 
		//existed not more than 10 lines.
        if(cnt==11) ans++,cnt=1;
        h=th;
		m=tm;
    }
    printf("%d\n",ans);
    return 0;
}