#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<set>
#include<iostream>
#define ll long long
#define clr(x,y) memset(x,y,sizeof(x))
using namespace std;
 
int n;
unsigned int dp[200005];
char s[100005];
 
int main(){
//    freopen("d:\\in.txt","r",stdin);
    cin>>n;
    scanf("%s",s+1);
    if(n%2==1){
        cout<<0;
        return 0;
    }
 
    int p = 100000,cnt=0;
    dp[p]=1;
    for(int i=1;i<=n;i++){
        p--;
        if(s[i]=='?'){
            int q = p+min(i-1,n-i);
            for(int j=p;j<=q;j++){
                    dp[j] += dp[j+2];
            }
            cnt++;
        }
    }
    unsigned int ans = dp[p];
    int k = n/2-(n-cnt);
    for(int i=0;i<k;i++) ans*=25;
    cout<<ans;
 
    return 0;
}