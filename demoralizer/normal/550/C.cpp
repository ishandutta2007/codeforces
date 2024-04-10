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
    char s[105];
    cin>>s;
    int n=strlen(s),a[n];
    for(int i=0;i<n;i++){
        a[i]=s[i]-'0';
        if(a[i]==0||a[i]==8){cout<<"YES\n"<<a[i];return 0;}
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int t=10*a[i]+a[j];
            if(t%8==0){
                cout<<"YES\n"<<t;return 0;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                int t=100*a[i]+10*a[j]+a[k];
                if(t%8==0){
                    cout<<"YES\n"<<t;return 0;
                }
            }
        }
    }
    cout<<"NO";
}