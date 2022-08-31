#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define MM 998244353
#define fr first
#define sc second
#define vc vector
#define pii pair<int,int>
#define psi pair<string,int>
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    char s[100005];
    cin>>s;
    int n=strlen(s);
    vc<int> a,b;
    for(int i=0;i<n-1;i++){
        if(s[i]=='A'&&s[i+1]=='B')a.pb(i);
        if(s[i]=='B'&&s[i+1]=='A')b.pb(i);
    }
    if(a.empty()||b.empty())goto no;
    if(a.size()==1&&b.size()==1){
        if(a[0]+1==b[0]||a[0]==b[0]+1)goto no;
    }
    if(a.size()==2&&b.size()==1){
        if(a[0]+1==b[0]||a[0]==b[0]+1)
            if(a[1]+1==b[0]||a[1]==b[0]+1)goto no;
    }
    if(a.size()==1&&b.size()==2){
        if(b[0]+1==a[0]||b[0]==a[0]+1)
            if(b[1]+1==a[0]||b[1]==a[0]+1)goto no;
    }
    cout<<"YES";
    return 0;
    no: cout<<"NO";
}