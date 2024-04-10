#include<bits/stdc++.h>
using namespace std;

int n,a[100005];
char s[100005],t[100005];

void mian(){
    cin>>n>>s;
    int ans=1e9;
    for(char e='a';e<='z';e++){
        int p=0;
        a[0]=0;
        for(int i=0;i<n;i++){
            if(s[i]==e)a[p]++;
            else{
                t[++p]=s[i];
                a[p]=0;
            }
        }
        bool valid=1;
        for(int i=1;i<p+1-i;i++)if(t[i]!=t[p+1-i])valid=0;
        if(valid){
            int cur=0;
            for(int i=0;i<=p-i;i++)cur+=abs(a[i]-a[p-i]);
            ans=min(ans,cur);
        }
    }
    if(ans==1e9)ans=-1;
    cout<<ans<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}