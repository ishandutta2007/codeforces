#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
char s[10003];
signed main()
{
    for(int T=read(); T--;)
    {
        scanf("%s",s+1);
        int n=strlen(s+1),cnt=0,sum=0,qwq=0;
        for(int i=1; i<=n; i++) 
        {
            if(s[i]=='0') ++cnt;
            if((s[i]-48)%2==0) ++qwq;
            sum+=s[i]-48;
        }
        if(n==cnt)
        {
            puts("red");
        }
        else
        {
            if(cnt==0)
            {
                puts("cyan");
            }
            else
            {
                if(qwq==1)
                {
                    puts("cyan");
                }
                else{
                    if(sum%3!=0)
                    {
                        puts("cyan");
                    }

                    else{puts("red");}
                }
            }

        }
    }
	return 0;
}