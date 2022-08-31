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
#define msi map<string,int>
#define mii map<int,int>
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,m;
    cin>>n>>m;
    if((n>m+1)||(m>2*(n+1))){
        cout<<-1;return 0;
    }
    int f,s,t;
    if(n>m){f=0;s=1;n--;m--;}
    else{
        f=1;m--;
        if(n>m){s=0;n--;}
        else {s=1;m--;}
    }
    cout<<f<<s;
    while(n+m>0){
        if(s==0){t=1;m--;}
        else if(f==1){t=0;n--;}
        else{
            if(n>m){t=0;n--;}
            else {t=1;m--;}
        }
        cout<<t;
        f=s;
        s=t;
    }
}