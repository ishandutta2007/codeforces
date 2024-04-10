#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=300005;
typedef pair<int,int> pii;
#define mk make_pair
int n,a[30],ans=0,bl[30],Over=0;
char s[N];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<26;i++) a[i]=1;
    for(int i=1;i<=n;i++)
    {
        char opt[2];
        scanf("%s",opt);
        scanf("%s",s+1);
        if(i==n) continue;
        int m=strlen(s+1);
        if(opt[0]=='!')
        {
            if(Over) ans++; 
            for(int j=0;j<26;j++) bl[j]=0;
            for(int j=1;j<=m;j++) bl[s[j]-'a']=1;
            for(int j=0;j<26;j++) a[j]&=bl[j];
        }
        if(opt[0]=='.')
        {
            for(int j=1;j<=m;j++) a[s[j]-'a']=0;
        }
        if(opt[0]=='?') 
        {
            if(Over) ans++;
            a[s[1]-'a']=0;
        }
        int tmp=0;
        for(int j=0;j<26;j++) tmp+=a[j];
        if(tmp==1) Over=1;
    }
    cout<<ans<<endl;
    return 0;
}