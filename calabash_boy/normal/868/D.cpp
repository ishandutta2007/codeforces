#include<bits/stdc++.h>  
#define rep(i,a,b) for(int i=a;i<=b;i++)  
#define dep(i,a,b) for(int i=a;i>=b;i--)  
#define mem(x,num) memset(x,num,sizeof x)  
using namespace std;  
const int maxn=206;  
int ans[maxn],n,m,l,r;  
string s[maxn];  
  
int work(int x){  
    rep(i,1,10)  
        rep(j,0,(1<<i)-1){  
            string t;  
            rep(k,0,i-1){  
                if(j&(1<<k))t+='1';  
                else t+='0';  
            }  
            if(s[x].find(t)==-1)return i-1;  
        }  
}  
int main()  
{  
    scanf("%d",&n);  
    rep(i,1,n)cin>>s[i];  
    scanf("%d",&m);  
    rep(i,1,m){  
        scanf("%d%d",&l,&r);  
        s[n+i]=s[l]+s[r];  
        if(s[n+i].length()>1000)s[n+i]=s[n+i].substr(0,500)+s[n+i].substr(s[n+i].length()-500,500);  
        ans[n+i]=max(max(ans[l],ans[r]),work(n+i));  
        cout<<ans[n+i]<<endl;  
    }  
    return 0;  
}