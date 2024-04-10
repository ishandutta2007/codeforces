#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
char s[4][4];
int main()
{
    bool f=0;
    for(int i=0;i<4;i++) scanf("%s",s[i]);
    for(int i=0;i<4;i++) for(int j=0;j<4;j++) if(s[i][j]=='.') if(i>0&&s[i-1][j]=='x'&&i<3&&s[i+1][j]=='x') f=1; else if(j>0&&s[i][j-1]=='x'&&j<3&&s[i][j+1]=='x') f=1; else if(j>0&&i>0&&s[i-1][j-1]=='x'&&j<3&&i<3&&s[i+1][j+1]=='x') f=1; else if(j>0&&i>0&&j<3&&i<3&&s[i-1][j+1]=='x'&&s[i+1][j-1]=='x') f=1; else if(i>1&&s[i-1][j]=='x'&&s[i-2][j]=='x') f=1; else if(j>1&&s[i][j-1]=='x'&&s[i][j-2]=='x') f=1; else if(i<2&&s[i+1][j]=='x'&&s[i+2][j]=='x') f=1; else if(j<2&&s[i][j+1]=='x'&&s[i][j+2]=='x') f=1; else if(i>1&&j>1&&s[i-1][j-1]=='x'&&s[i-2][j-2]=='x') f=1; else if(i<2&&j<2&&s[i+1][j+1]=='x'&&s[i+2][j+2]=='x') f=1; else if(i>1&&j<2&&s[i-1][j+1]=='x'&&s[i-2][j+2]=='x') f=1; else if(i<2&&j>1&&s[i+1][j-1]=='x'&&s[i+2][j-2]=='x') f=1;
    puts(f?"YES":"NO");
    return 0;
}